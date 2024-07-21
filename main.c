#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "config.h"
#include "debug.h"
#include "timing.h"
#include "sdl_utils.h"

int main(int argc, char *argv[]) {
    parse_arguments(argc, argv);

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!init_sdl(&window, &renderer)) {
        return 1;
    }

    bool quit = false;
    SDL_Event event;

    Uint32 start_time = SDL_GetTicks();
    Uint64 frame_count = 0;
    Uint32 fps_timer = start_time;
    Uint64 total_frame_count = 0;

    while (!quit) {
        Uint64 frame_start = SDL_GetPerformanceCounter();

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        frame_count++;
        total_frame_count++;
        Uint32 elapsed_time = SDL_GetTicks() - start_time;

        if (SDL_GetTicks() - fps_timer >= 1000) {
            if (debug_mode) {
                printf("Frames: %lu, Current FPS: %lu, Time elapsed: %u ms\n", total_frame_count, frame_count, elapsed_time);
            }
            frame_count = 0;
            fps_timer = SDL_GetTicks();
        }

        delay_frame(frame_start);
    }

    close_sdl(window, renderer);

    return 0;
}
