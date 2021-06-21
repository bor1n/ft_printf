#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (result)
	{
		ft_strlcpy(result, s1, ft_strlen(s1) + 1);
		result[ft_strlen(s1)] = 0;
		return (result);
	}
	return (0);
}
