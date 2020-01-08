/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

int *my_calloc_int(int nbr)
{
	int *a = malloc (sizeof(int) * nbr);

	for (int b = 0; b < nbr; b++)
		a[b] = 0;
	return (a);
}

void free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free (tab[i]);
	free(tab);
}

int len_tab(char **tab)
{
	int i;

	for (i = 0; tab[i] != NULL; i++);
	return (i);
}

int is_number(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	for (; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

int rev_int(int nbr)
{
	int mask = 0x000000FF;
	int lele = nbr << 24;
	int le = nbr >> 8 << 24 >> 8;
	int ri = nbr >> 16 << 24 >> 16;
	int riri = nbr >> 24;
	int rev;

	riri = riri & mask;
	mask = mask << 8;
	ri = ri & mask;
	mask = mask << 8;
	le = le & mask;
	mask = mask << 8;
	lele = lele & mask;
	rev = lele | le | ri | riri;
	return (rev);
}
