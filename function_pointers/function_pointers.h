#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h> /* For NULL */

int _putchar(char c);
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */
