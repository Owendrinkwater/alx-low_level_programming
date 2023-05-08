#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of file to create
 * @text_content: pointer to a string to insert in the file
 *
 * Return: - 1 or - -1 if fail
 */

int create_file(const char *filename, char *text_content)
{
	int fd, v, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	v = write(fd, text_content, length);

	if (fd == -1 || v == -1)
		return (-1);

	close(fd);

	return (1);
}
