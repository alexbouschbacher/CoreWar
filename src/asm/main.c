/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

void search_error(int src)
{
	off_t begin;
	func_t *funcs;

	begin = error_header(src) + 1;
	lseek(src, begin, SEEK_SET);
	funcs = find_funcs(src, begin);
	lseek(src, begin, SEEK_SET);
	error_fill_prog(src, funcs);
	lseek(src, 0, SEEK_SET);
}

void do_it(int src, int dest)
{
	header_t header;
	off_t begin;
	func_t *funcs;

	memset(&header, 0, sizeof (header_t)); //A remplacer par le memset
	begin = set_header(&header, src) + 1;
	header.prog_size = rev_int(find_size(src));
	write(dest, &header, sizeof (header_t));
	lseek(src, begin, SEEK_SET);
	funcs = find_funcs(src, begin);
	lseek(src, begin, SEEK_SET);
	fill_prog(src, dest, funcs);
}

int main(int ac, char **av)
{
	int fd;
	int dest;

	if (ac != 2) {
		my_putstr("Put a file\n");
		return (84);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1) {
		my_putstr("Invalid file\n");
		return (84);
	}
	search_error(fd);
	dest = open(get_name(av[1]), O_CREAT | O_WRONLY | O_TRUNC, 00755);
	if (dest == -1) {
		my_putstr("Unable to create\n");
		return (84);
	}
	do_it(fd, dest);
}
