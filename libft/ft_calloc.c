#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	memory;

	memory = count * size;
	result = malloc(memory);
	if (result)
	{
		ft_bzero(result, memory);
		return (result);
	}
	return (0);
}
