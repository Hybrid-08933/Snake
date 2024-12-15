#include <SDL2/SDL_timer.h>
#include <stdlib.h>
#include <stdint.h>

#include "defs.h"
#include "structs.h"
#include "food.h"
#include "snake_utils.h"

void snake_initialize(void) {
    app.head = (Snake_Head*) malloc(sizeof(Snake_Head));

    // Head
    app.head->body = (Snake_Body*) malloc(sizeof(Snake_Body));
    app.head->dir = SNAKE_DIR_RIGHT;
    app.head->pos_x = (SCREEN_WIDTH / SNAKE_SIZE) / 2;
    app.head->pos_y = (SCREEN_HEIGHT / SNAKE_SIZE) / 2;

    // Body
    app.head->body->dir = SNAKE_DIR_RIGHT;
    app.head->body->pos_x = app.head->pos_x - SNAKE_SIZE;
    app.head->body->pos_y = app.head->pos_y;
    app.head->body->next = NULL;
}

void snake_move(void) {

    switch (app.head->dir) {
        case SNAKE_DIR_RIGHT:
            app.head->pos_x = (app.head->pos_x + SNAKE_SIZE) % SCREEN_WIDTH;
            break;
        
        case SNAKE_DIR_UP:
            if (app.head->pos_y <= 0) {
                app.head->pos_y = SCREEN_HEIGHT - SNAKE_SIZE;
            } else {
                app.head->pos_y = app.head->pos_y - SNAKE_SIZE;
            }
            break;
        
        case SNAKE_DIR_LEFT:
            if (app.head->pos_x <= 0) {
                app.head->pos_x = SCREEN_WIDTH - SNAKE_SIZE;
            } else {
                app.head->pos_x = app.head->pos_x - SNAKE_SIZE;
            }
            break;
        
        case SNAKE_DIR_DOWN:
            app.head->pos_y = (app.head->pos_y + SNAKE_SIZE) % SCREEN_HEIGHT;
            break;

        default:
            break; 
    }

    for (Snake_Body *tmp_body = app.head->body; tmp_body != NULL; tmp_body = tmp_body->next) {
        switch (tmp_body->dir) {
        case SNAKE_DIR_RIGHT:
            tmp_body->pos_x = (tmp_body->pos_x + SNAKE_SIZE) % SCREEN_WIDTH;
            break;
        
        case SNAKE_DIR_UP:
            if (tmp_body->pos_y <= 0) {
                tmp_body->pos_y = SCREEN_HEIGHT - SNAKE_SIZE;
            } else {
                tmp_body->pos_y = tmp_body->pos_y - SNAKE_SIZE;
            }
            break;
        
        case SNAKE_DIR_LEFT:
            if (tmp_body->pos_x <= 0) {
                tmp_body->pos_x = SCREEN_WIDTH - SNAKE_SIZE;
            } else {
                tmp_body->pos_x = tmp_body->pos_x - SNAKE_SIZE;
            }
            break;
        
        case SNAKE_DIR_DOWN:
            tmp_body->pos_y = (tmp_body->pos_y + SNAKE_SIZE) % SCREEN_HEIGHT;
            break;

        default:
            break;
        }
    }
}

void snake_body_redir(void) {
    Snake_Direction tmp, tmp_2;
    Snake_Body *prev_body = app.head->body;
    tmp = prev_body->dir;
    prev_body->dir = app.head->dir;

    for (Snake_Body *tmp_body = prev_body->next; tmp_body != NULL; tmp_body = tmp_body->next) {
        tmp_2 = tmp_body->dir;
        tmp_body->dir = tmp;
        tmp = tmp_2;
    }
}

void snake_grow(void) {
    Snake_Body *new_body = (Snake_Body*) malloc(sizeof(Snake_Body));
    Snake_Body *tmp_body = app.head->body;

    while (tmp_body->next != NULL) tmp_body = tmp_body->next;

    new_body->dir = tmp_body->dir;

    if (new_body->dir == SNAKE_DIR_LEFT) {
        new_body->pos_x = tmp_body->pos_x + SNAKE_SIZE;
    } else if (new_body->dir == SNAKE_DIR_RIGHT) {
        new_body->pos_x = tmp_body->pos_x - SNAKE_SIZE;
    } else {
        new_body->pos_x = tmp_body->pos_x;
    }

    if (new_body->dir == SNAKE_DIR_DOWN) {
        new_body->pos_y = tmp_body->pos_y - SNAKE_SIZE;
    } else if (new_body->dir == SNAKE_DIR_UP) {
        new_body->pos_y = tmp_body->pos_y + SNAKE_SIZE;
    } else {
        new_body->pos_y = tmp_body->pos_y;
    }

    new_body->next = NULL;
    tmp_body->next = new_body;
}

void snake_collision(void) {
    int_fast16_t head_x, head_y;

    if (((app.head->pos_x + SNAKE_SIZE) >= app.food_x && app.head->pos_x <= (app.food_x + SNAKE_SIZE)) && ((app.head->pos_y + SNAKE_SIZE) >= app.food_y && app.head->pos_y <= (app.food_y + SNAKE_SIZE))) {
        snake_grow();
        spawn_food();
    }

    switch (app.head->dir) {
        case SNAKE_DIR_RIGHT:
            head_x = app.head->pos_x;
            head_y = app.head->pos_y;
            for (Snake_Body *tmp_body = app.head->body; tmp_body != NULL; tmp_body = tmp_body->next) {
                if (head_x == tmp_body->pos_x && head_y == tmp_body->pos_y) {
                    SDL_Delay(1500);
                    exit(1);
                }
            }
            break;
        
        case SNAKE_DIR_UP:
            head_x = app.head->pos_x;
            head_y = app.head->pos_y;
            for (Snake_Body *tmp_body = app.head->body; tmp_body != NULL; tmp_body = tmp_body->next) {
                if ((head_x == tmp_body->pos_x && head_y == tmp_body->pos_y)) {
                    SDL_Delay(1500);
                    exit(1);
                }
            }
            break;
        
        case SNAKE_DIR_LEFT:
            head_x = app.head->pos_x;
            head_y = app.head->pos_y;
            for (Snake_Body *tmp_body = app.head->body; tmp_body != NULL; tmp_body = tmp_body->next) {
                if (head_x == tmp_body->pos_x && head_y == tmp_body->pos_y) {
                    SDL_Delay(1500);
                    exit(1);
                }
            }
            break;
        
        case SNAKE_DIR_DOWN:
            head_x = app.head->pos_x;
            head_y = app.head->pos_y;
            for (Snake_Body *tmp_body = app.head->body; tmp_body != NULL; tmp_body = tmp_body->next) {
                if (head_x == tmp_body->pos_x && head_y == tmp_body->pos_y) {
                    SDL_Delay(1500);
                    exit(1);
                }
            }
            break;
        
        default:
            break;
    }
}
