#include "main.h"

/**
 * append_text_to_file - appends teext at end file
 * @filename: pointer to file
 * @text_content: string to add to end of file
 *
 * Return: if func fails - -1
 *	if file not exist user lacks perm - -1
 *	otherwise - 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, length);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}

