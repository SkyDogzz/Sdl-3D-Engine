#ifndef TIMING_H
#define TIMING_H

#include <SDL2/SDL.h>

void busy_wait(double milliseconds);
void delay_frame(Uint64 frame_start);

#endif // TIMING_H
