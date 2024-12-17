#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL_render.h>

#include "defs.h"

#if LINKED_LIST
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
    int_fast16_t food_x, food_y;
} App;

extern App app;

#elif TILE_SET
typedef enum {
    SNAKE_NOTHING,
    SNAKE_FOOD,
    SNAKE_HEAD_RIGHT,
    SNAKE_HEAD_UP,
    SNAKE_HEAD_LEFT,
    SNAKE_HEAD_DOWN,
    SNAKE_BODY
} Snake;

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    Snake snake[SCREEN_WIDTH][SCREEN_HEIGHT];
    int8_t head_x, head_y;
} App;

extern App app;
#endif

#endif
