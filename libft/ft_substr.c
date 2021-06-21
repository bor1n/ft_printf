#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		counter;
	size_t	s_len;

	if (s == 0)
		return (0);
	counter = 0;
	s_len = ft_strlen(s);
	if (s_len < len)
		result = ft_calloc(s_len + 1, sizeof(char));
	else
		result = ft_calloc(len + 1, sizeof(char));
	if (result == 0)
		return (0);
	ft_bzero(result, 1);
	if (s_len < start)
		return (result);
	while (*(s + start) && counter < (int)(len))
	{
		result[counter] = *(s + start);
		start++;
		counter++;
	}
	result[counter] = 0;
	return (result);
}
