#include "includes/ft_printf.h"

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

char	get_space_symbol(int zero)
{
	if (zero == 1)
		return ('0');
	return (' ');
}
