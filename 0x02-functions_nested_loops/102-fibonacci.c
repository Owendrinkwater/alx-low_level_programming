#include <stdio.h>
/**
 *main  - entry point
 *
 * return: always 0
 *
 */

int main(void)
{
	int i, n = 50;
	int fib1 = 1, fib2 = 2, fib;

	printf("%d, %d", fib1, fib2);

	for (i = 3; i <= n; i++)
	{
	 fib = fib1 + fib2;

	printf(", %d", fib);
	fib1 = fib2;
	fib2 = fib;
	}

	printf("\n");
	return (0);
}
