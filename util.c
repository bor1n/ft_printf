#include "includes/ft_printf.h"

int get_power_of(unsigned int d, int base)
{
	int result;

	if (d == 0 || d == 1)
		return (1);
	result = 0;
	while (d > 0)
	{
		d /= base;
		result++;
	}
	return (result);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	get_int_length(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

int	calculate_width(int arg, int width)
{
	int width_length;

	width_length = get_int_length(width);
	if (width_length == 0)
		return arg * 10;
	else
	{
		while (width_length != 0)
		{
			arg *= 10;
			width_length--;
		}
		arg += width;
		return arg;
	}
}

char	get_space_symbol(int zero)
{
	if (zero == 1)
		return ('0');
	return (' ');
}