#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			counter;
	unsigned char	temp;

	if (dst == 0 && src == 0)
		return (dst);
	counter = 0;
	while (counter < n)
	{
		temp = *(unsigned char *) src;
		*(unsigned char *) dst = temp;
		counter++;
		dst++;
		src++;
		if (temp == (unsigned char) c)
			return (dst);
	}
	return (NULL);
}
