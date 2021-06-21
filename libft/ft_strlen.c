#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (*s != 0)
	{
		res++;
		s++;
	}
	return (res);
}
