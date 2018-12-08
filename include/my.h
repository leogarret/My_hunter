/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** include
*/

#ifndef __LIST__
#define __LIST__
#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define ERROR_MESSAGE "Un problème est survenue"
#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080
#define WINDOW_TITLE "EpiHunt"

sfRenderWindow *create_window(char *title, int width, int height);
void analyse_events(sfRenderWindow *window, sfEvent event);
void game();
void my_putchar(char c);
void my_putstr(char *str);
int numberOfArguments(char *str);
int my_put_nbr(int b);
void my_printf(char *str, ...);
void event_manager(sfRenderWindow *window, sfEvent event, bird_t *bird);
void scope(init_t *init);
void parallax(init_t *init_ptr, sfVector2f *cloudVec, sfVector2f *cloud2Vec);
void draw(init_t *init_ptr, bird_t *bird);
void clear_data(init_t *init_ptr, bird_t *bird);
init_t init_data();
void init_window(init_t *init);
void init_textures(init_t *init);
void init_text(init_t *init);
void init_sprites(init_t *init);
bird_t new_bird(init_t *init);
void init_bird(bird_t *bird);
void bird_movement(bird_t *bird, init_t *init);
void move_rect(sfIntRect *rect, int size_move, int rectMax);
void collision(bird_t *bird, sfVector2i mouse_vector);
void set_random_position(bird_t *bird);
#endif /* __LIST */