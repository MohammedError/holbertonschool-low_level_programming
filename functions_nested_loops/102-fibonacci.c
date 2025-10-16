#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers, starting with 1 and 2.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	long int fib1 = 1;
	long int fib2 = 2;
	long int next;

	printf("%ld", fib1);

	for (i = 2; i <= 50; i++)
	{
		printf(", %ld", fib2);
		next = fib1 + fib2;
		fib1 = fib2;
		fib2 = next;
	}

	printf("\n");
	return (0);
}
