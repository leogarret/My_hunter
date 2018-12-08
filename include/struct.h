/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** include
*/

#include <SFML/Graphics.h>

typedef struct event_s
{
    sfEvent event;
} event_t;

typedef struct window_s
{
    sfRenderWindow *window;
} window_t;

typedef struct texture_s
{
    sfTexture* bg;
    sfTexture* cloud;
    sfTexture* cloud2;
    sfTexture* scope;
    sfTexture* hearth;
} texture_t;

typedef struct sprite_s
{
    sfSprite* sBg;
    sfSprite* sCloud;
    sfSprite* sCloud2;
    sfSprite* sScope;
    sfSprite* sHearth;
} sprite_t;

typedef struct text_s
{
    sfFont* font;
    sfText* score;
} text_t;

typedef struct bird_s
{
    sfVector2f bird_size;
    sfVector2f position;
    sfTexture* img_bird;    
    sfSprite* sImg_Bird;
    sfIntRect moveRect;
    sfVector2f movement;
    sfBool hit_bird;
    int rectMax;
    int score;
    sfBool is_level2;
} bird_t;

typedef struct my_clock_s
{
    sfClock* clock;
    sfTime time;
    float seconds;
} my_clock_t;

typedef struct init_s
{
    event_t event;
    window_t display;
    texture_t texture;
    sprite_t sprite;
    text_t text;
} init_t;