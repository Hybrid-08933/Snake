#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "structs.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "snake.h"
#include "main.h"

App app;

int main(int argc, char *argv[]) {
    memset(&app, 0, sizeof(App));

    init_SDL();

    atexit(cleanup);

    while(1) {
        prepare_scene();

        snake_draw();

        snake_move();

        snake_body_redir();

        present_scene();

        snake_collision();

        process_input();

        SDL_Delay(144);
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
