#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = s;
	while (n--)
		*str++ = 0;
}
