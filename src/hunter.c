/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** hunter.c
*/

#include "../include/my.h"

void call_function(init_t *init, bird_t *bird)
{
    draw(init, bird);
    bird_movement(bird, init);
    scope(init);
    sfRenderWindow_display(init->display.window);
}

void game(void)
{
    init_t init = init_data();
    bird_t bird = new_bird(&init);
    my_clock_t clock;
    sfVector2f parallax_vector[2] = {{0, 0}, {DISPLAY_WIDTH, 0}};

    clock.clock = sfClock_create();
    sfRenderWindow_setVerticalSyncEnabled(init.display.window, sfTrue);
    while (sfRenderWindow_isOpen(init.display.window)) {
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.seconds = clock.time.microseconds / 1000000.0;
        event_manager(init.display.window, init.event.event, &bird);
        sfRenderWindow_clear(init.display.window, sfBlack);
        if (clock.seconds > 0.09) {
            move_rect(&bird.moveRect, 598, bird.rectMax);
            sfClock_restart(clock.clock);
        }
        parallax(&init, &parallax_vector[0], &parallax_vector[1]);
        call_function(&init, &bird);
    }
    clear_data(&init, &bird);
}