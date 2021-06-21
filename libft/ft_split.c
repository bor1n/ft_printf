#include "libft.h"

static unsigned int	get_count_of_words(char const *s, char delimiter)
{
	unsigned int	result;
	unsigned int	count;

	count = 0;
	result = 0;
	while (*(s + count))
	{
		if (*(s + count) == delimiter && count != 0)
			if (*(s + count - 1) != delimiter)
				result++;
		count++;
	}
	if (count != 0 && *(s + count - 1) != delimiter)
		result++;
	return (result);
}

static void	get_next_word(char **s, unsigned int *word_len, char delimiter)
{
	unsigned int	i;

	i = 0;
	*s += *word_len;
	*word_len = 0;
	while (**s && **s == delimiter)
		(*s)++;
	while ((*s)[i])
	{
		if ((*s)[i] == delimiter)
			return ;
		i++;
		(*word_len)++;
	}
}

static void	**ft_freemem(void **data)
{
	int	count;

	count = 0;
	while (data[count])
	{
		free(data[count]);
		count++;
	}
	free(data);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	char			*str;
	unsigned int	word_len;
	unsigned int	y;
	unsigned int	count_of_words;

	if (s == 0)
		return (0);
	count_of_words = get_count_of_words(s, c);
	result = ft_calloc((count_of_words + 1), sizeof(char *));
	if (result == 0)
		return (0);
	str = (char *) s;
	word_len = 0;
	y = 0;
	while (y < count_of_words)
	{
		get_next_word(&str, &word_len, c);
		result[y] = ft_substr(str, 0, word_len);
		if (result[y] == 0)
			return ((char **)(ft_freemem((void **) result)));
		y++;
	}
	result[y] = 0;
	return (result);
}
