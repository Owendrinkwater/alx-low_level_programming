#include <stdio.h>
/**
 * main - entry point
 *
 * description: prints alphabet in lowercase and uppercase
 *
 * return: always (0) sucess
 */

int main(void)
{
	char lowercase;
	char uppercase;

	for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
	{
		putchar (lowercase);
	}

	for (uppercase = 'A'; uppercase <= 'Z'; uppercase++)
	{
		putchar (uppercase);
	}

	putchar ('\n');
	return (0);
}
