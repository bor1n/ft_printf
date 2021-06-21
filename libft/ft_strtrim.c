#include "libft.h"

static int	check(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	count;
	char	*result;

	if (s1 == 0)
		return (NULL);
	count = 0;
	while (check(set, *(s1 + count)))
		count++;
	start = count;
	count = ft_strlen(s1) - 1;
	while (check(set, *(s1 + count)) && count != 0)
		count--;
	end = count;
	if (end == 0)
	{
		result = malloc(sizeof(char));
		result[0] = 0;
		return (result);
	}
	result = ft_substr(s1, start, end - start + 1);
	if (result == 0)
		return (0);
	return (result);
}
