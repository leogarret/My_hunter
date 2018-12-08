/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** init.c
*/

#include "../include/my.h"

init_t init_data()
{
    init_t init;
    init_t *init_ptr = &init;

    init_window(init_ptr);
    init_textures(init_ptr);
    init_text(init_ptr);
    init_sprites(init_ptr);
    return (init);
}

void init_window(init_t *init)
{
    init->display.window = create_window(WINDOW_TITLE, 
    DISPLAY_WIDTH, DISPLAY_HEIGHT);
    sfRenderWindow_setFramerateLimit(init->display.window, 60);
}

void init_textures(init_t *init)
{
    init->texture.bg = sfTexture_createFromFile
    ("sprites/background_01/b1_01.png", NULL);
    init->texture.cloud = sfTexture_createFromFile
    ("sprites/background_01/b1_02.png", NULL);
    init->texture.cloud2 = sfTexture_createFromFile
    ("sprites/background_01/b1_02.png", NULL);
    init->texture.scope = sfTexture_createFromFile
    ("sprites/scope.png", NULL);
    init->texture.hearth = sfTexture_createFromFile
    ("sprites/coeur.png", NULL);
    init->sprite.sBg = sfSprite_create();
    init->sprite.sCloud = sfSprite_create();
    init->sprite.sCloud2 = sfSprite_create();
    init->sprite.sScope = sfSprite_create();
    init->sprite.sHearth = sfSprite_create();
}

void init_text(init_t *init)
{
    sfVector2f vectorText = {900, 50};

    init->text.score = sfText_create();
    init->text.font = sfFont_createFromFile("fonts/amsterdam.ttf");
    sfText_setString(init->text.score, "Niveau 1");
    sfText_setFont(init->text.score, init->text.font);
    sfText_setCharacterSize(init->text.score, 50);
    sfText_setPosition(init->text.score, vectorText);
}

void init_sprites(init_t *init)
{
    sfSprite_setTexture(init->sprite.sBg, init->texture.bg, sfTrue);
    sfSprite_setTexture(init->sprite.sCloud, init->texture.cloud, sfTrue);
    sfSprite_setTexture(init->sprite.sCloud2, init->texture.cloud2, sfTrue);
    sfSprite_setTexture(init->sprite.sScope, init->texture.scope, sfTrue);
    sfSprite_setTexture(init->sprite.sHearth, init->texture.hearth, sfTrue);
}