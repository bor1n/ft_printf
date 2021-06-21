#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		counter;

	if (s1 == 0 || s2 == 0)
		return (0);
	counter = 0;
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (result == 0)
		return (0);
	while (*s1)
	{
		result[counter] = *s1;
		s1++;
		counter++;
	}
	while (*s2)
	{
		result[counter] = *s2;
		s2++;
		counter++;
	}
	result[counter] = 0;
	return (result);
}
