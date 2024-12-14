#include <SDL2/SDL_events.h>
#include <stdlib.h>

#include "input.h"
#include "structs.h"
#include "snake.h"

void process_input(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_q:
                    exit(0);
                
                case SDLK_d:
                    if (app.head->dir != SNAKE_DIR_LEFT) {
                        app.head->dir = SNAKE_DIR_RIGHT;
                    }
                    break;
                
                case SDLK_w:
                    if (app.head->dir != SNAKE_DIR_DOWN) {
                        app.head->dir = SNAKE_DIR_UP;
                    }
                    break;
                
                case SDLK_a:
                    if (app.head->dir != SNAKE_DIR_RIGHT) {
                        app.head->dir = SNAKE_DIR_LEFT;
                    }
                    break;
                
                case SDLK_s:
                    if (app.head->dir != SNAKE_DIR_UP) {
                        app.head->dir = SNAKE_DIR_DOWN;
                    }
                    break;
                
                default:
                    break;
            }
            SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
        }
    }
}
