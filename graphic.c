#include "graphics.h"
#include <stdint.h>

#define VGA_ADDRESS 0xA0000
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define COLOR_WHITE 15

void put_pixel(int x, int y, uint8_t color) {
    uint8_t* vga = (uint8_t*)VGA_ADDRESS;
    vga[y * SCREEN_WIDTH + x] = color;
}

void init_graphics() {
    // Set video mode 13h (320x200, 256 colors)
    asm volatile (
        "mov $0x0013, %ax\n\t"
        "int $0x10"
    );
}

void draw_logo() {
    // Simple logo: A white square in the center
    for (int y = 90; y < 110; y++) {
        for (int x = 140; x < 180; x++) {
            put_pixel(x, y, COLOR_WHITE);
        }
    }
}

void draw_progress_bar(int progress) {
    for (int y = 180; y < 190; y++) {
        for (int x = 60; x < 260; x++) {
            if (x < 60 + progress * 2) {
                put_pixel(x, y, COLOR_WHITE);
            } else {
                put_pixel(x, y, 0);  // Clear
            }
        }
    }
}
