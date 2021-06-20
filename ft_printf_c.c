#include "includes/ft_printf.h"

static int	print_align_left(unsigned char c, int width)
{
	int		temp;

	ft_putchar_fd(c, 1);
	temp = 1;
	while (temp < width)
	{
		ft_putchar_fd(' ', 1);
		temp++;
	}
	return (width);
}

static int print_align_right(unsigned char c, int width, t_flags flags)
{
	char	space_symbol;
	int		temp;

	temp = 0;
	space_symbol = get_space_symbol(flags.zero);
	while (temp < width - 1)
	{
		ft_putchar_fd(space_symbol, 1);
		temp++;
	}
	ft_putchar_fd(c, 1);
	return (width);
}


int ft_printf_c(t_flags flags, int c)
{
	int		width;

	width = max(1, flags.width);
	if (flags.minus == 1)
		return (print_align_left((unsigned char)c, width));
	else
		return (print_align_right((unsigned char)c, width, flags));
}