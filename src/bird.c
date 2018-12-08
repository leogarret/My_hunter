/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** graphics.c
*/

#include <time.h>
#include "../include/my.h"
#include <stdio.h>

bird_t new_bird(init_t *init)
{
    bird_t bird;
    init_bird(&bird);
    return (bird);
}

void set_random_position(bird_t *bird)
{
    srand(time(0));
    if (bird->position.x > DISPLAY_WIDTH || bird->hit_bird) {
        bird->hit_bird = sfFalse;
        if (bird->is_level2)
            bird->movement.x = rand()%15;
        else
            bird->movement.x = rand()%10;
        bird->position.y = rand()%DISPLAY_HEIGHT - 100;
        while (bird->position.y <= 100 || bird->position.y >= DISPLAY_HEIGHT - 100)
	        bird->position.y = rand()%DISPLAY_HEIGHT - 100;
        bird->position.x = -200;
        sfSprite_setRotation(bird->sImg_Bird, 0);
        sfSprite_setPosition(bird->sImg_Bird, bird->position);
        bird->hit_bird = sfFalse;
    }
}

void collision(bird_t *bird, sfVector2i mouse_vector)
{
    if ((mouse_vector.x >= bird->position.x && \
        mouse_vector.x <= (bird->position.x + 70))) {
            if (mouse_vector.y >= bird->position.y && \
                mouse_vector.y <= (bird->position.y + 70)) {
                bird->hit_bird = sfTrue;
                set_random_position(bird);
                bird->score += 1;
            }
    }
}

void bird_movement(bird_t *bird, init_t *init)
{
    if (bird->movement.x < 5)
        bird->movement.x = 5;
    bird->position = sfSprite_getPosition(bird->sImg_Bird);
    sfSprite_setTextureRect(bird->sImg_Bird, bird->moveRect);
    sfSprite_move(bird->sImg_Bird, bird->movement);
    sfRenderWindow_drawSprite(init->display.window, bird->sImg_Bird, NULL);
    set_random_position(bird);
    if (bird->score >= 10 && !bird->is_level2) {
        bird->is_level2 = sfTrue;
        sfText_setString(init->text.score, "Niveau 2");
    }
}

void init_bird(bird_t *bird)
{
    bird->img_bird = sfTexture_createFromFile("sprites/bird.png", NULL);
    bird->sImg_Bird = sfSprite_create();
    sfSprite_setTexture(bird->sImg_Bird, bird->img_bird, sfTrue);
    bird->bird_size = (sfVector2f){0.2, 0.2};
    bird->moveRect.top = 0;
    bird->moveRect.left = 0;
    bird->moveRect.width = 598;
    bird->moveRect.height = 406;
    bird->rectMax = 1196;
    sfSprite_setScale(bird->sImg_Bird, bird->bird_size);
    bird->position.x = 200;
    bird->position.y = 400;
    sfSprite_setPosition(bird->sImg_Bird, bird->position);
}