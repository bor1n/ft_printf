#include "includes/ft_printf.h"

static int	print_precision(unsigned int d, int precision, char *base)
{
	int	result;

	result = get_power_of(d, 16);
	while (result < precision)
	{
		ft_putchar_fd('0', 1);
		result++;
	}
	ft_putunbr_base_fd(d, base, 1);
	return (result);
}

static int	print_align_left(unsigned int d, int width, t_flags flags,
							   char *base)
{
	int		temp;

	temp = 0;
	if (!((flags.precision == 0 || (flags.default_prec && flags.dot))
			&& d == 0))
		temp += print_precision(d, flags.precision, base);
	while (temp < width)
	{
		ft_putchar_fd(' ', 1);
		temp++;
	}
	return (width);
}

static int	print_align_right(unsigned int d, int width, t_flags flags,
								char *base)
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
	if ((flags.precision == 0 || (flags.default_prec && flags.dot))
		&& d == 0)
		ft_putchar_fd(space_symbol, 1);
	else
		print_precision(d, flags.precision, base);
	return (width);
}

static int	check_solo_dot(t_flags flags, unsigned int d)
{
	if (flags.width == 0 && flags.dot && d == 0)
	{
		if (flags.default_prec || flags.precision == 0)
			return (1);
	}
	return (0);
}

int	ft_printf_x(t_flags flags, unsigned int d, char *base)
{
	int		width;

	if (check_solo_dot(flags, d))
		return (0);
	width = max(max(get_power_of(d, 16), flags.precision), flags.width);
	if (flags.minus == 1)
		return (print_align_left(d, width, flags, base));
	else
		return (print_align_right(d, width, flags, base));
}
