#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	length;
	size_t	count;

	count = 0;
	length = ft_strlen(s);
	while (count < length + 1)
	{
		if (*s == (unsigned char) c)
			return ((char *)(s));
		count++;
		s++;
	}
	return (0);
}
