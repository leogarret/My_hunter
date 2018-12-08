/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** graphics.c
*/

#include "../include/my.h"

void parallax(init_t *init_ptr, sfVector2f *cloudVec, sfVector2f *cloud2Vec)
{
    cloudVec->x -= 1.5;
    cloud2Vec->x -= 1.5;
    sfSprite_setPosition(init_ptr->sprite.sCloud, *cloudVec);
    sfSprite_setPosition(init_ptr->sprite.sCloud2, *cloud2Vec);
    if (cloudVec->x <= 0 - DISPLAY_WIDTH)
        cloudVec->x = DISPLAY_WIDTH;
    else if (cloud2Vec->x <= 0 - DISPLAY_WIDTH)
        cloud2Vec->x = DISPLAY_WIDTH;
}

void draw(init_t *init_ptr, bird_t *bird)
{
    sfRenderWindow_drawSprite(init_ptr->display.window, 
    init_ptr->sprite.sBg, NULL);
    sfRenderWindow_drawSprite(init_ptr->display.window, 
    init_ptr->sprite.sCloud, NULL);
    sfRenderWindow_drawSprite(init_ptr->display.window, 
    init_ptr->sprite.sCloud2, NULL);
    sfSprite_setPosition(init_ptr->sprite.sHearth, (sfVector2f){DISPLAY_WIDTH - 100, 50});
    sfSprite_setScale(init_ptr->sprite.sHearth, (sfVector2f){0.07, 0.07});
    sfRenderWindow_drawSprite(init_ptr->display.window, 
    init_ptr->sprite.sHearth, NULL);
    sfRenderWindow_drawText(init_ptr->display.window, 
    init_ptr->text.score, NULL);
}

void clear_data(init_t *init_ptr, bird_t *bird)
{
    sfSprite_destroy(init_ptr->sprite.sBg);
    sfSprite_destroy(init_ptr->sprite.sCloud);
    sfSprite_destroy(init_ptr->sprite.sCloud2);
    sfTexture_destroy(init_ptr->texture.bg);
    sfTexture_destroy(init_ptr->texture.cloud);
    sfTexture_destroy(init_ptr->texture.scope);
    sfTexture_destroy(init_ptr->texture.cloud2);
    sfRenderWindow_drawText(init_ptr->display.window, 
    init_ptr->text.score, NULL);
    sfSprite_destroy(bird->sImg_Bird);
    sfSprite_destroy(init_ptr->sprite.sScope);
}