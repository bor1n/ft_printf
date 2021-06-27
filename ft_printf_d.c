#include "includes/ft_printf.h"

static int	print_precision(int d, t_flags flags)
{
	int	result;
	int	minus;

	minus = 0;
	if (d < 0)
	{
		ft_putchar_fd('-', 1);
		d *= -1;
		minus = 1;
	}
	result = int_length(d);
	while (result < flags.precision)
	{
		ft_putchar_fd('0', 1);
		result++;
	}
	ft_putunbr_fd(d, 1);
	return (result + minus);
}

static int	print_align_left(int d, int width, t_flags flags)
{
	int		temp;

	temp = 0;
	if (!((flags.precision == 0 || (flags.default_prec && flags.dot))
			&& d == 0))
		temp += print_precision(d, flags);
	while (temp < width)
	{
		ft_putchar_fd(' ', 1);
		temp++;
	}
	if (d < 0)
		temp++;
	return (temp);
}

static int	print_align_right(int d, int width, t_flags flags)
{
	char	space_symbol;
	int		temp;
	int		minus;

	temp = 0;
	minus = 0;
	space_symbol = get_space_symbol(flags.zero);
	if (d < 0 && space_symbol == '0')
	{
		ft_putchar_fd('-', 1);
		d *= -1;
		minus = 1;
		width--;
	}
	while (temp++ < width - max(int_length(d), flags.precision) - (d < 0))
		ft_putchar_fd(space_symbol, 1);
	if ((flags.precision == 0 || (flags.default_prec && flags.dot)) && d == 0)
		ft_putchar_fd(space_symbol, 1);
	else
		print_precision(d, flags);
	if (minus == 1)
		width += 2;
	return (width);
}

static int	check_solo_dot(t_flags flags, int d)
{
	if (flags.width == 0 && flags.dot && d == 0)
	{
		if (flags.default_prec || flags.precision == 0)
			return (1);
	}
	return (0);
}

int	ft_printf_d(t_flags flags, int d)
{
	int		width;

	if (check_solo_dot(flags, d))
		return (0);
	width = max(max(int_length(d) + (d < 0), flags.precision), flags.width);
	if (flags.minus == 1)
		return (print_align_left(d, width, flags));
	else
		return (print_align_right(d, width, flags));
}
