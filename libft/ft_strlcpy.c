#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	src_len;

	if (dst == 0 || src == 0)
		return (0);
	count = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (count < dstsize - 1 && *src)
	{
		*dst = *src;
		count++;
		dst++;
		src++;
	}
	*dst = 0;
	return (src_len);
}
