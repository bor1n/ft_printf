#include "includes/ft_printf.h"

static int	print_precision(unsigned int d, int precision, char *base)
{
	int result;

	result = get_power_of(d, 16);
	while (result < precision)
	{
		ft_putchar_fd('0', 1);
		result++;
	}
	ft_putunbr_base_fd(d, base, 1);
	return (result);
}

static int	print_align_left(unsigned int d, int width, t_flags flags, char *base)
{
	int		temp;

	temp = print_precision(d, flags.precision, base);
	while (temp < width)
	{
		ft_putchar_fd(' ', 1);
		temp++;
	}
	return (width);
}

static int print_align_right(unsigned int d, int width, t_flags flags, char *base)
{
	char	space_symbol;
	int		temp;

	temp = 0;
	space_symbol = get_space_symbol(flags.zero);
	while (temp < width - max(get_power_of(d, 16), flags.precision))
	{
		ft_putchar_fd(space_symbol, 1);
		temp++;
	}
	print_precision(d, flags.precision, base);
	return (width);
}

int	ft_printf_x(t_flags flags, unsigned int d, char *base)
{
	int		width;

	if (flags.precision == 0 && d == 0)
		return (0);
	width = max(max(get_power_of(d, 16), flags.precision), flags.width);
	if (flags.minus == 1)
		return (print_align_left(d, width, flags, base));
	else
		return (print_align_right(d, width, flags, base));
}