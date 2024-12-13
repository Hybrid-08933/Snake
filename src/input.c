#include <SDL2/SDL_events.h>
#include <stdlib.h>

#include "input.h"

void process_input(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(1);
            break;
        
        default:
            break;
        }
    }
}
