/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

void my_strcpy2(char *cpy, char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		cpy[i] = str[i];
	cpy[i] = 0;
}

char *my_strncpy(char *str, int n)
{
	char *cpy = malloc (sizeof (char) * n + 1);

	for (int i = 0; i < n; i++)
		cpy[i] = str[i];
	cpy[n] = '\0';
	return (cpy);
}

char *my_strcpy(char *str)
{
	int len = my_strlen(str);
	char *cpy = malloc (sizeof (char) * (len + 1));

	for (int i = 0; str[i]; i++)
		cpy[i] = str[i];
	cpy[len] = '\0';
	return (cpy);
}
