/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

int error_header(int src)
{
	char *line;
	char *info;
	int read = 0;
	int chars = 0;

	while ((line = get_next_line(src)) != NULL && read < 2) {
		printf("h[%s]\n", line);
		chars += my_strlen(line) + 1;
		if (line[0] == '#')
			continue;
		info = get_info(line, read);
		if (read == 0 && (info == NULL || my_strlen(info) > 128)) {
			my_putstr("Bad name\n");
			exit (84);
		}
		if (read == 1 && (info == NULL || my_strlen(info) > 2048)) {
			my_putstr("Bad comment\n");
			exit (84);
		}
		free (info);
		read++;
	}
	return (chars);
}
