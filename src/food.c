#include <stdbool.h>
#include <stdlib.h>

#include "defs.h"
#include "structs.h"
#include "food.h"

void spawn_food(void) {
    bool spawned = false;

    while (!spawned) {
        app.food_x = (abs(rand()) % (SCREEN_WIDTH / SNAKE_SIZE)) * SNAKE_SIZE;
        app.food_y = (abs(rand()) % (SCREEN_HEIGHT / SNAKE_SIZE)) * SNAKE_SIZE;

        for (Snake_Body *tmp_body = app.head->body; tmp_body != NULL; tmp_body = tmp_body->next) {
            if (tmp_body->pos_x == app.food_x && tmp_body->pos_y == app.food_y) {
                continue;
            }
        }

        spawned = true;
    }
}
