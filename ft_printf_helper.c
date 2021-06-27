#include "includes/ft_printf.h"

void	get_width(t_flags *flags, const char **format, va_list *args)
{
	int	width;

	if (**format == '*')
	{
		flags->width = va_arg(*args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width *= -1;
		}
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		if (flags->width != 0)
			flags->width = calculate_width(flags->width, width);
		else
			flags->width = width;
	}
}

static void	get_precision_digit(t_flags *flags, const char **format)
{
	int	precision;

	if (ft_isdigit(**format))
	{
		flags->zero = 0;
		flags->default_prec = 0;
		precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		if (flags->asterisk == 1)
			flags->precision = flags->precision * 10 + precision;
		else
			flags->precision = precision;
	}
}

void	get_precision(t_flags *flags, const char **format, va_list *args)
{
	if (**format == '.')
	{
		(*format)++;
		flags->dot = 1;
		if (**format == '*')
		{
			flags->precision = va_arg(*args, int);
			if (flags->precision >= 0)
				flags->zero = 0;
			flags->asterisk = 1;
			flags->default_prec = 0;
			(*format)++;
		}
		get_precision_digit(flags, format);
	}
}
