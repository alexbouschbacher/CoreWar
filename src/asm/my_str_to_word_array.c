/*
** EPITECH PROJECT, 2017
** my_str_word_to_array
** File description:
** segment a string
*/

#include <stdlib.h>

static int count_words (char const *str, char sep)
{
	int words = 0;
	int now;
	int next;

	for (int i = 0 ; str[i]; i++) {
		now = (str[i] == sep) ? 1 : 0;
		next = (str[i + 1] == sep || str[i + 1] == '\0') ? 1 : 0;
		if (next != now && now == 0)
			words += 1;
	}
	return (words);
}

static char **tabl_malloc (int words, char const *str, char sep)
{
	int count_ltr = 0;
	int x = 0;
	char **tab;

	tab = malloc (sizeof (char *) * (words + 1));
	for (int i = 0 ; str[i]; i++) {
		if (str[i] != sep) {
			count_ltr += 1;
			if (str[i + 1] == '\0' || str[i + 1] == sep) {
				count_ltr += 1;
				tab[x] = malloc (sizeof (char) * count_ltr + 1);
				x += 1;
				count_ltr = 0;
			}
		} else {
			count_ltr = 0;
		}
	}
	return (tab);
}

static void implant (char const *str, char **tab, char sep)
{
	int x = 0;
	int y = 0;

	for (int i = 0 ; str[i]; i++) {
		if (str[i] != sep) {
			tab[x][y] = str[i];
			y += 1;
			if (str[i + 1] == '\0')
				tab[x++][y] = '\0';
			else if (str[i + 1] == sep) {
				tab[x++][y] = '\0';
				y = 0;
			}
		}
	}
	tab[x] = NULL;
}

char **my_str_to_word_array(char *str, char sep)
{
	int words = count_words(str, sep);
	char **tab = tabl_malloc (words, str, sep);
	implant (str, tab, sep);
	return (tab);
}
