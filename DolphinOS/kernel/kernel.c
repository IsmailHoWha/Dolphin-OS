#include "graphics.h"

void kernel_main() {
    // Initialize loading screen
    init_graphics();
    draw_logo();
    draw_progress_bar(0);

    // Simulate loading
    for (int i = 0; i <= 100; i++) {
        draw_progress_bar(i);
        // Delay to simulate loading time
        for (volatile int j = 0; j < 100000; j++);
    }

    // Continue with kernel initialization...
}
