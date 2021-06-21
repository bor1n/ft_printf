#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	count;
	int	length;

	count = 0;
	length = (int) n;
	while (count < length)
	{
		if (*(unsigned char *) s == (unsigned char) c)
			return ((void *)(s));
		count++;
		s++;
	}
	return (NULL);
}
