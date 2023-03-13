#include "main.h"
/**
 * prints the n times table
 * @n is the number
 * returns nothing
 */

void print_times_table(int n)
{
	int i, j;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int product = i * j;

			if (n > 15 || n < 0)
			{
			}
			else if (j == 0)
			{
				_putchar(product + '0');
			} else
			{
				_putchar(',');
				_putchar(' ');
				_putchar((product / 10) + '0');
				_putchar((product % 10) + '0');
			}
		}
		_putchar('\n');
	}
}


