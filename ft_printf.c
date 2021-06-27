#include "includes/ft_printf.h"

void	get_width(t_flags *flags, const char **format, va_list *args);
void	get_precision(t_flags *flags, const char **format, va_list *args);

void	get_args(t_flags *flags, const char **format, va_list *args)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->asterisk = 0;
	flags->precision = 1;
	flags->default_prec = 1;
	flags->type = 0;
	flags->zero_char = 0;
	while (**format == '0')
	{
		flags->zero = 1;
		flags->zero_char = 1;
		(*format)++;
	}
	while (**format == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
		(*format)++;
	}
	get_width(flags, format, args);
	get_precision(flags, format, args);
	flags->type = **format;
}

int	parse(t_flags flags, va_list *args)
{
	if (flags.type == 's')
		return (ft_printf_s(flags, va_arg(*args, char *)));
	if (flags.type == 'c')
		return (ft_printf_c(flags, va_arg(*args, int)));
	if (flags.type == '%')
		return (ft_printf_c(flags, '%'));
	if (flags.type == 'd' || flags.type == 'i')
		return (ft_printf_d(flags, va_arg(*args, int)));
	if (flags.type == 'u')
		return (ft_printf_u(flags, va_arg(*args, int)));
	if (flags.type == 'x')
		return (ft_printf_x(flags, va_arg(*args, int), "0123456789abcdef"));
	if (flags.type == 'X')
		return (ft_printf_x(flags, va_arg(*args, int), "0123456789ABCDEF"));
	if (flags.type == 'p')
		return (ft_printf_p(flags, va_arg(*args, void *)));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		result;

	result = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			get_args(&flags, &format, &args);
			result += parse(flags, &args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			result += 1;
		}
		format++;
	}
	va_end(args);
	return (result);
}
