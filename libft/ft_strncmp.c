#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		return (-1);
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) == 0)
			return (-*(unsigned char *)(s2 + i));
		if (*(unsigned char *)(s2 + i) == 0)
			return (*(unsigned char *)(s1 + i));
		if (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		{
			i++;
			continue ;
		}
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	}
	return (0);
}
