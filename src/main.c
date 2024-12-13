#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "structs.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "main.h"

App app;

int main(int argc, char *argv[]) {
    memset(&app, 0, sizeof(App));

    init_SDL();

    atexit(cleanup);

    while(1) {
        prepare_scene();

        process_input();

        present_scene();

        SDL_Delay(16);
    }

    return 0;
}

void cleanup(void) {
    SDL_DestroyRenderer(app.renderer);
    app.renderer = NULL;

    SDL_DestroyWindow(app.window);
    app.window = NULL;

    SDL_Quit();
}
