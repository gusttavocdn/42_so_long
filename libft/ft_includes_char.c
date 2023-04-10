#include "libft.h"

int ft_includes_char(char c, const char *chars)
{
	size_t i;

	if (!chars)
		return (FALSE);

	i = 0;
	while (chars[i])
	{
		if (chars[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
