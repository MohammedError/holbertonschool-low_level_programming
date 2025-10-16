#include <stdio.h>

/**
 * main - Finds and prints the sum of the even-valued terms
 * in the Fibonacci sequence whose values do not exceed 4,000,000.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int fib1 = 1, fib2 = 2, next, sum = 2;

	while (1)
	{
		next = fib1 + fib2;
		if (next > 4000000)
			break;

		if (next % 2 == 0)
			sum += next;

		fib1 = fib2;
		fib2 = next;
	}
	printf("%ld\n", sum);
	return (0);
}
