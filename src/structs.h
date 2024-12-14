#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL_render.h>

typedef enum {
    SNAKE_DIR_NONE,
    SNAKE_DIR_RIGHT,
    SNAKE_DIR_UP,
    SNAKE_DIR_LEFT,
    SNAKE_DIR_DOWN
} Snake_Direction;

typedef struct Snake_Body {
    Snake_Direction dir;
    int_fast16_t pos_x, pos_y;
    struct Snake_Body *next;
} Snake_Body;

typedef struct {
    Snake_Direction dir;
    int_fast16_t pos_x, pos_y;
    Snake_Body *body;
} Snake_Head;

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    Snake_Head *head;
} App;

extern App app;

#endif
