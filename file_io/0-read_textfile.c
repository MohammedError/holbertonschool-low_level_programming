#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t len_r, len_w;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	len_r = read(fd, buffer, letters);
	if (len_r == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	len_w = write(STDOUT_FILENO, buffer, len_r);

	free(buffer);
	close(fd);

	if (len_w != len_r)
		return (0);

	return (len_w);
}
