#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>

#include "defs.h"
#include "structs.h"

void prepare_scene(void) {
    SDL_SetRenderDrawColor(app.renderer, BACKGROUND_RED_COMPONENT, BACKGROUND_GREEN_COMPONENT, BACKGROUND_BLUE_COMPONENT, BACKGROUND_ALPHA_COMPONENT);
    SDL_RenderClear(app.renderer);
}

void present_scene(void) {
    SDL_RenderPresent(app.renderer);
}

void snake_draw(void) {
    Uint8 r = SNAKE_HEAD_RED_COMPONENT, g = SNAKE_HEAD_GREEN_COMPONENT, b = SNAKE_HEAD_BLUE_COMPONENT, a = BACKGROUND_ALPHA_COMPONENT;
    SDL_Rect rect = {
        .x = app.head->pos_x,
        .y = app.head->pos_y,
        .w = SNAKE_SIZE,
        .h = SNAKE_SIZE
    };

    SDL_SetRenderDrawColor(app.renderer, r, g, b, a);
    SDL_RenderFillRect(app.renderer, &rect);

    r = SNAKE_BODY_RED_COMPONENT;
    g = SNAKE_BODY_GREEN_COMPONENT;
    b = SNAKE_BODY_BLUE_COMPONENT;

    SDL_SetRenderDrawColor(app.renderer, r, g, b, a);

    for (Snake_Body *tmp_body = app.head->body; tmp_body != NULL; tmp_body = tmp_body->next) {
        rect.x = tmp_body->pos_x;
        rect.y = tmp_body->pos_y;

        SDL_RenderFillRect(app.renderer, &rect);
    }
}

void food_draw(void) {
    Uint8 r = FOOD_RED_COMPONENT, g = FOOD_GREEN_COMPONENT, b = FOOD_BLUE_COMPONENT, a = BACKGROUND_ALPHA_COMPONENT;
    SDL_Rect rect = {
        .x = app.food_x,
        .y = app.food_y,
        .w = SNAKE_SIZE,
        .h = SNAKE_SIZE
    };

    SDL_SetRenderDrawColor(app.renderer, r, g, b, a);
    SDL_RenderFillRect(app.renderer, &rect);
}
