# Define the cross-compiler
CC = i686-elf-gcc
AS = nasm
LD = i686-elf-ld
CFLAGS = -ffreestanding -nostdlib -nostartfiles -nodefaultlibs

# Output binaries
BOOTLOADER_BIN = bootloader.bin
KERNEL_BIN = kernel.bin

# Build rules
all: $(BOOTLOADER_BIN) $(KERNEL_BIN) os-image

$(BOOTLOADER_BIN): bootloader/boot.asm
	$(AS) $< -f bin -o $@

$(KERNEL_BIN): kernel/kernel.c kernel/graphics.c
	$(CC) $(CFLAGS) -Ttext 0x1000 $^ -o $@

os-image: $(BOOTLOADER_BIN) $(KERNEL_BIN)
	cat $(BOOTLOADER_BIN) $(KERNEL_BIN) > iso/boot/DolphinOS.bin

iso: os-image
	mkdir -p iso/boot/grub
	cp iso/boot/grub/grub.cfg iso/boot/grub/
	grub-mkrescue -o DolphinOS.iso iso

clean:
	rm -f $(BOOTLOADER_BIN) $(KERNEL_BIN) iso/boot/DolphinOS.bin DolphinOS.iso
