/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

char *get_name(char *str)
{
	int len = my_strlen(str);
	char *file;
	int c;

	if (str[len - 1] == 's' && str[len - 2] == '.') {
		file = malloc (sizeof (char) * len + 3);
		c = 0;
	} else {
		file = malloc (sizeof (char) * len + 5);
		c = 2;
	}
	for (int i = 0; i < len + c - 2; i++)
		file[i] = str[i];
	file[len + c - 2] = '.';
	file[len + c - 1] = 'c';
	file[len + c] = 'o';
	file[len + c + 1] = 'r';
	file[len + c + 2] = '\0';
	return (file);
}

char *get_arg(char *str)
{
	int len = 0;
	int i;
	int j;
	char *cpy;

	for (i = 0; str[i] != '\0' && str[i] != 34; i++);
	if (str[i] != 34)
		return (NULL);
	j = i + 1;
	for (i++; str[i] != '\0' && str[i] != 34; i++)
		len++;
	if (str[i] == '\0')
		return (NULL);
	for (i++; str[i] != '\0'; i++)
		return (NULL);
	cpy = malloc (sizeof (char) * len + 1);
	for (i = 0; str[j] != 34; j++)
		cpy[i++] = str[j];
	cpy[len] = '\0';
	return (cpy);
}

char *get_info(char *str, int info)
{
	if (info == 0) {
		if (my_strncmp(".name ", str, 6) == 0)
			return (get_arg(str));
	} else if (info == 1)
		if (my_strncmp(".comment ", str, 9) == 0)
			return (get_arg(str));
	return (NULL);
}

int set_header(header_t *header, int src)
{
	char *line;
	char *info;
	int read = 0;
	int chars = 0;

	header->magic = rev_int(COREWAR_EXEC_MAGIC);
	while ((line = get_next_line(src)) != NULL && read < 2) {
		printf("sh[%s]\n", line);
		chars += my_strlen(line) + 1;
		if (line[0] == '#')
			continue;
		info = get_info(line, read);
		if (read == 0 && (info == NULL || my_strlen(info) > 128)) {
			my_putstr("Bad name\n");
			exit (84);
		} else if (read == 0)
			my_strcpy2(header->prog_name, info);
		if (read == 1 && (info == NULL || my_strlen(info) > 2048)) {
			my_putstr("Bad comment\n");
			exit (84);
		} else if (read == 1)
			my_strcpy2(header->comment, info);
		free (info);
		read++;
	}
	return (chars);
}
