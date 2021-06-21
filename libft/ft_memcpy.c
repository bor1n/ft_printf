#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	counter;

	if (dst == 0 && src == 0)
		return (dst);
	counter = 0;
	while (counter < (int) n)
	{
		*(unsigned char *)(dst + counter) = *(unsigned char *)(src + counter);
		counter++;
	}
	return (dst);
}
