#include "includes/ft_printf.h"

void get_args(t_flags *flags, const char **format, va_list *args)
{
	int width;
	int precision;
/* c s d i u x X*/
/* % p */
    flags->zero = 0;
    flags->minus = 0;
    flags->width = 0;
    flags->dot = 0;
	flags->asterisk = 0;
    flags->precision = 1;
    if (**format == '0')
    {
        flags->zero = 1;
		(*format)++;
    }
    if (**format == '-')
    {
        flags->minus = 1;
        flags->zero = 0;
		(*format)++;
    }
    if (**format == '*')
    {
        flags->width = va_arg(*args, int);
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
    if (**format == '.')
    {
		(*format)++;
		flags->zero = 0;
		flags->dot = 1;
	    if (**format == '*')
	    {
		    flags->width = va_arg(*args, int);
			(*format)++;
			flags->asterisk = 1;
	    }
	    if (ft_isdigit(**format))
	    {
			precision = ft_atoi(*format);
		    while (ft_isdigit(**format))
				(*format)++;
		    if (flags->asterisk == 1)
			    flags->precision = flags->precision * 10 + precision;
		    else
		    	flags->precision = precision;
	    }
    }
	flags->type = **format;
}

int    parse(t_flags flags, va_list *args)
{
	if (flags.type == 's')
		return ft_printf_s(flags, va_arg(*args, char *));
	if (flags.type == 'c')
		return ft_printf_c(flags, va_arg(*args, int));
	if (flags.type == '%')
		return ft_printf_c(flags, '%');
	if (flags.type == 'd' || flags.type == 'i')
		return ft_printf_d(flags, va_arg(*args, int));
	if (flags.type == 'u')
		return ft_printf_u(flags, va_arg(*args, int));
	if (flags.type == 'x')
		return ft_printf_x(flags, va_arg(*args, int), "0123456789abcdef");
	if (flags.type == 'X')
		return ft_printf_x(flags, va_arg(*args, int), "0123456789ABCDEF");
	return (1);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    t_flags flags;
    int result;

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