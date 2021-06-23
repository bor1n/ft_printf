#include "includes/ft_printf.h"

static void	putstr_len(char *s, int length)
{
	while(length > 0)
	{
		ft_putchar_fd(*s, 1);
		length--;
		s++;
	}
}

static int	get_length(char *s, t_flags flags)
{
	if (flags.dot == 1)
		return (min(flags.precision, (int)ft_strlen(s)));
	return ((int)ft_strlen(s));
}

static int	print_align_left(char *s, int width, t_flags flags)
{
	int length;

	length = get_length(s, flags);
	putstr_len(s, length);
	while (length < width)
	{
		ft_putchar_fd(' ', 1);
		length++;
	}
	return (width);
}

static int print_align_right(char *s, int width, t_flags flags)
{
	char	space_symbol;
	int		length_s;
	int		temp;

	temp = 0;
	space_symbol = get_space_symbol(flags.zero);
	length_s = get_length(s, flags);
	while (temp < width - length_s)
	{
		ft_putchar_fd(space_symbol, 1);
		temp++;
	}
	putstr_len(s, length_s);
	return (width);
}

int ft_printf_s(t_flags flags, char *s) {
    int width;

    if (s == 0)
        return ft_printf_s(flags, "(null)");
	if (flags.dot && flags.default_precision)
	    flags.precision = 0;
	if (flags.precision < 0)
	    flags.precision = (int)ft_strlen(s);
	width = max(get_length(s, flags), flags.width);
	if (flags.minus == 1)
		return (print_align_left(s, width, flags));
	else
		return (print_align_right(s, width, flags));
}