#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

bool init_sdl(SDL_Window** window, SDL_Renderer** renderer);
void close_sdl(SDL_Window* window, SDL_Renderer* renderer);

#endif // SDL_UTILS_H
