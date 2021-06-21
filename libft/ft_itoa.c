#include "libft.h"

static char	*zero(void)
{
	char	*result;

	result = malloc(2);
	if (result == 0)
		return (NULL);
	ft_strlcpy(result, "0", 2);
	return (result);
}

static int	get_size(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	fill(char *result, int n, int size)
{
	int		temp;
	char	symbol;

	while (n != 0)
	{
		temp = n % 10;
		if (temp < 0)
			temp *= -1;
		symbol = (char)(temp + '0');
		result[size] = symbol;
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		sign;

	if (n == 0)
		return (zero());
	size = get_size(n);
	sign = 0;
	if (n < 0)
		sign = 1;
	result = malloc(size + sign + 1);
	if (result == 0)
		return (NULL);
	result[size + sign] = 0;
	fill(result, n, size + sign - 1);
	if (sign == 1)
		result[0] = '-';
	return (result);
}
