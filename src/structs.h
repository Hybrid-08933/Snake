#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL_render.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

extern App app;

#endif
