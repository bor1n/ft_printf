#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	count;

	count = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (*(dst + count))
		count++;
	while (*src && count < dstsize - 1)
	{
		*(dst + count) = *src;
		src++;
		count++;
	}
	*(dst + count) = 0;
	return (ft_strlen(src) + ft_strlen(dst));
}
