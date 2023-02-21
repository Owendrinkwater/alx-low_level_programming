#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase ten times
 *                      followed by a new line
 *
 * Return: Nothing
 */
void print_alphabet_x10(void)
{
	char ch;
	int i;

	i = 0;

	while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}
