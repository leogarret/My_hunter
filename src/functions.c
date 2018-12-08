/*
** EPITECH PROJECT, 2018
** Léo Garret
** File description:
** functions.c
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int number_of_arguments(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '%')
            count++;
        i++;
    }
    return (i);
}

int my_put_nbr(int b)
{
    if (b == -2147483648) {
	my_putchar('-');
	my_putchar('2');
	b = 147483648;
    }
    if (b < 0) {
	my_putchar('-');
	my_put_nbr(-b);
	return (0);
    }
    if (b < 10) {
	my_putchar('0' + b);
	return (0);
    }
    my_put_nbr(b / 10);
    my_putchar('0' + b % 10);
    return (0);
}

void my_printf(char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%')
            my_put_nbr(va_arg(args, int));
        else
            my_putchar(str[i]);
    }
    va_end(args);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 0;
    int min = 0;

    while (str[i] != '\0') {
        result *= 10;
        result += str[i];
    }
    while (str = "-") {
        min++;
    }
    return (min % 2 == 0 ? result : result * (-1));
}