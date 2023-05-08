#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads text file
 * @filename: text file read
 * @letters: number of letters to read
 * Return: actual number of letters read and printed or 0 fail
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t t;
	ssize_t fd;
	ssize_t w;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
