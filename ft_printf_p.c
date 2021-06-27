#include "includes/ft_printf.h"

static int	print_precision(unsigned long p, t_flags flags)
{
	int	result;

	ft_putstr_fd("0x", 1);
	result = get_power_of_long(p, 16);
	while (result < flags.precision)
	{
		ft_putchar_fd('0', 1);
		result++;
	}
	ft_putunbr_base_fd(p, "0123456789abcdef", 1);
	return (result + 2);
}

static int	print_align_left(unsigned long p, int width, t_flags flags)
{
	int	temp;

	temp = 0;
	if (!((flags.precision == 0 || (flags.default_prec && flags.dot))
			&& p == 0))
		temp += print_precision(p, flags);
	else
	{
		ft_putstr_fd("0x", 1);
		temp += 2;
	}
	while (temp < width)
	{
		ft_putchar_fd(' ', 1);
		temp++;
	}
	return (temp);
}

static int	print_align_right(unsigned long p, int width, t_flags flags)
{
	char	space_symbol;
	int		temp;

	temp = 0;
	space_symbol = get_space_symbol(flags.zero);
	while (temp < width - max(get_power_of_long(p, 16) + 2, flags.precision))
	{
		ft_putchar_fd(space_symbol, 1);
		temp++;
	}
	if ((flags.precision == 0 || (flags.default_prec && flags.dot))
		&& p == 0)
	{
		ft_putchar_fd(space_symbol, 1);
		ft_putstr_fd("0x", 1);
		temp += 2;
	}
	else
		temp += print_precision(p, flags);
	return (temp);
}

int	ft_printf_p(t_flags flags, void *p)
{
	int				width;
	unsigned long	link;
	int				p_length;

	if ((flags.default_prec || flags.precision == 0) && flags.dot
		&& p == 0)
	{
		if (flags.width < 2)
			flags.width = 2;
		flags.dot = 0;
		return (ft_printf_s(flags, "0x"));
	}
	link = (unsigned long)p;
	p_length = get_power_of_long(link, 16);
	width = max(max(p_length, flags.precision), flags.width);
	if (flags.minus == 1)
		return (print_align_left(link, width, flags));
	else
		return (print_align_right(link, width, flags));
}
