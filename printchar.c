#include <unistd.h>

/**
 * printchar - write the character c to stdout
 * @c: The character tio print
 * Return: 1 on success.
 * On error, -1 is returned, and errno is set appropriately.
 */

int printchar(char c)
{
	return (write(1, &c, 1));
}
