#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: The string to print
 *
 * Description: Prints the second half.
 * If odd, prints last n = (length + 1) / 2 chars.
 * Return: Nothing.
 */
void puts_half(char *str)
{
	int len = 0;
	int i, n;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		n = len / 2;
	else
		n = (len + 1) / 2;

	for (i = n; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
