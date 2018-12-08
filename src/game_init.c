/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** game_init.c
*/

#include "../include/my.h"

sfRenderWindow *create_window(char *title, int width, int height)
{
    sfVideoMode video_mode = {width, height, 64};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, title, sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}