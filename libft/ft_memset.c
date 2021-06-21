#include <string.h>

void	*ft_memset(void *b, char c, size_t len)
{
	size_t	counter;

	counter = 0;
	while (counter < len)
	{
		*(unsigned char *) &b[counter] = c;
		counter++;
	}
	return (b);
}
