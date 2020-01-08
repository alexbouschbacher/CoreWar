/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"
#include <limits.h>

int my_getnbr(char const *str)
{
	long number = 0;
	int nega = 1;

	while (*str == '-' || *str == '+') {
		if (*str == '-')
			nega *= -1;
		str++;
	}
	while (*str != '\0') {
		if (*str < '0' || *str > '9')
			break;
		number = number * 10 + (*str - '0');
		if (number * nega < INT_MIN || number * nega > INT_MAX)
			return (84);
		str++;
	}
	return (number * nega);
}

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}

int my_strncmp(char *s1, char *s2, int i)
{
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	if (len1 < i || len2 < i)
		return (1);
	for (int j = 0; j < i; j++) {
		if (s1[j] != s2[j])
			return (1);
	}
	return (0);
}

int my_strcmp(char *s1, char *s2)
{
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	if (len1 != len2)
		return (1);
	for (int j = 0; j < len1; j++) {
		if (s1[j] != s2[j])
			return (1);
	}
	return (0);
}
