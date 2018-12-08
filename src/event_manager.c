/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** event_manager.c
*/

#include "../include/my.h"

void event_manager(sfRenderWindow *window, sfEvent event, bird_t *bird)
{
    sfVector2i vectorMouse;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtMouseButtonPressed) {
            vectorMouse = sfMouse_getPosition((sfWindow*)window);
            collision(bird, vectorMouse);
        }
    }
}

void move_rect(sfIntRect *rect, int size_move, int rectMax)
{
    if (rect->left < rectMax)
        rect->left += size_move;
    else
        rect->left = 0;
}

void scope(init_t *init)
{
    sfVector2f vectorMouse;
    vectorMouse.x = sfMouse_getPosition((sfWindow*)init->display.window).x - 40;
    vectorMouse.y = sfMouse_getPosition((sfWindow*)init->display.window).y - 40;

    sfSprite_setScale(init->sprite.sScope, (sfVector2f){0.4, 0.4});
    sfSprite_setPosition(init->sprite.sScope, vectorMouse);
    sfRenderWindow_drawSprite(init->display.window, init->sprite.sScope, NULL);
}