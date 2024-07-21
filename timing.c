#include "timing.h"
#include "config.h"

void busy_wait(double milliseconds) {
    Uint64 start = SDL_GetPerformanceCounter();
    Uint64 end;
    double elapsed;
    do {
        end = SDL_GetPerformanceCounter();
        elapsed = (double)((end - start) * 1000) / SDL_GetPerformanceFrequency();
    } while (elapsed < milliseconds);
}

void delay_frame(Uint64 frame_start) {
    Uint64 frame_end = SDL_GetPerformanceCounter();
    double frame_time = (double)((frame_end - frame_start) * 1000) / SDL_GetPerformanceFrequency();

    if (frame_time < TARGET_FRAME_TIME) {
        SDL_Delay((Uint32)(TARGET_FRAME_TIME - frame_time));
        busy_wait(TARGET_FRAME_TIME - frame_time - (Uint32)(TARGET_FRAME_TIME - frame_time));
    }
}
