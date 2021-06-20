#include "includes/ft_printf.h"

static int	d_is_negative(int d)
{
	if (d < 0)
		return (1);
	return (0);
}

static int	print_precision(int d, int precision)
{
	int result;
	int minus;

	minus = 0;
	result = get_int_length(d);
	if (d < 0)
	{
		ft_putchar_fd('-', 1);
		d *= -1;
		minus = 1;
	}
	while (result < precision)
	{
		ft_putchar_fd('0', 1);
		result++;
	}
	ft_putunbr_fd(d, 1);
	result += minus;
	return (result);
}

static int	print_align_left(int d, int width, t_flags flags)
{
	int		temp;

	temp = print_precision(d, flags.precision);
	while (temp < width)
	{
		ft_putchar_fd(' ', 1);
		temp++;
	}
	return (width);
}

static int print_align_right(int d, int width, t_flags flags)
{
	char	space_symbol;
	int		temp;

	temp = 0;
	space_symbol = get_space_symbol(flags.zero);
	while (temp < width - max(get_int_length(d), flags.precision) - d_is_negative(d))
	{
		ft_putchar_fd(space_symbol, 1);
		temp++;
	}
	print_precision(d, flags.precision);
	return (width);
}

int	ft_printf_d(t_flags flags, int d)
{
	int		width;

	if (flags.precision == 0 && d == 0)
		return (0);
	width = max(max(get_int_length(d) + d_is_negative(d), flags.precision), flags.width);
	if (flags.minus == 1)
		return (print_align_left(d, width, flags));
	else
		return (print_align_right(d, width, flags));
}