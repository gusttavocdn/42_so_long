#include "libft.h"

size_t ft_strfull(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != c)
			return (0);
		i++;
	}

	return (i);
}