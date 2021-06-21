#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	needle_len;

	count = 0;
	needle_len = ft_strlen(needle);
	if (ft_strncmp(haystack + count, needle, needle_len) == 0)
		return ((char *)(haystack + count));
	while (*(haystack + count) && count < len && len - count >= needle_len)
	{
		if (ft_strncmp(haystack + count, needle, needle_len) == 0)
			return ((char *)(haystack + count));
		count++;
	}
	return (NULL);
}
