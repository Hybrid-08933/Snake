#include <SDL2/SDL_render.h>

#include "defs.h"
#include "structs.h"

void prepare_scene(void) {
    SDL_SetRenderDrawColor(app.renderer, BACKGROUND_RED_COMPONENT, BACKGROUND_GREEN_COMPONENT, BACKGROUND_BLUE_COMPONENT, BACKGROUND_ALPHA_COMPONENT);
    SDL_RenderClear(app.renderer);
}

void present_scene(void) {
    SDL_RenderPresent(app.renderer);
}
