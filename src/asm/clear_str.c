/*
** EPITECH PROJECT, 2018
** Clear_Stirng
** File description:
** segment the string
*/

#include "main.h"

static int is_end(char *str, int i)
{
	i++;
	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

static int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int size_of(char *str)
{
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (is_space (str[i]) == 1)
			continue;
		len++;
		if (is_space (str[i + 1]) == 1 && is_end(str, i) == 1)
			len++;
	}
	len++;
	return (len);
}

char *clear_str(char *str)
{
	char *ret;
	int p = 0;

	if (str == NULL)
		return (NULL);
	ret = malloc (size_of(str));
	for (int i = 0; str[i] != '\0'; i++) {
		if (is_space (str[i]) == 1)
			continue;
		ret[p++] = str[i];
		if (is_space (str[i + 1]) == 1 && is_end(str, i) == 1)
			ret[p++] = ' ';
	}
	ret[p] = '\0';
	free(str);
	return (ret);
}
