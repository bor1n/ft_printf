#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	x;

	if (dst == 0 && src == 0)
		return (dst);
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		x = (int) len - 1;
		while (x >= 0)
		{
			*(unsigned char *)(dst + x) = *(unsigned char *)(src + x);
			x--;
		}
	}
	return (dst);
}
