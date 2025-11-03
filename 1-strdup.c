#include "main.h"
#include <stdlib.h>

char *_strdup(char *str)
{
	char *dup_str;
	unsigned int i, len;

	if (!str)
		return (NULL);

	for (len = 0; str[len]; len++)
		;

	dup_str = malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);

	for (i = 0; i < len; i++)
		dup_str[i] = str[i];
	dup_str[len] = '\0';

	return (dup_str);
}
