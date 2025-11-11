#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h> /* For printf */

/**
 * print_all - prints anything
 * @format: list of types of arguments passed
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str;
	char *sep = ""; /* Separator string, starts empty */

	va_start(args, format);

	if (format) /* Only run if format string is not NULL */
	{
		while (format[i]) /* 1st WHILE loop */
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sep, va_arg(args, int));
					break;
				case 'i':
					printf("%s%d", sep, va_arg(args, int));
					break;
				case 'f':
					/* Floats are promoted to double when passed */
					printf("%s%f", sep, va_arg(args, double));
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL) /* 1st IF */
						str = "(nil)";
					printf("%s%s", sep, str);
					break;
				default:
					i++;
					continue; /* Skip non-format chars */
			}
			sep = ", "; /* Set separator after first print */
			i++;
		}
	}

	printf("\n");
	va_end(args);
}
