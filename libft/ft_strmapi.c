#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		count;

	if (s == 0)
		return (NULL);
	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (result == 0)
		return (NULL);
	count = 0;
	while (*(s + count))
	{
		result[count] = (f)(count, *(s + count));
		count++;
	}
	result[count] = 0;
	return (result);
}
