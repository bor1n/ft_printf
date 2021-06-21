#include "libft.h"

static int	check_long(char *str, int sign)
{
	int	count;

	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		count++;
	}
	if (count >= 18)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (2);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	res = 0;
	if (check_long((char *)str, sign) != 2)
		return (check_long((char *)str, sign));
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
