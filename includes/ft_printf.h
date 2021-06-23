#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include<stdarg.h>

typedef struct	s_flags
{
	int     zero;
	int     minus;
	int     width;
	int		dot;
	int     asterisk;
	int     precision;
	int     default_precision;
	char    type;
}				t_flags;

int	max(int x, int y);
int	min(int x, int y);
int	calculate_width(int arg, int width);
char	get_space_symbol(int zero);
int	get_int_length(int n);
int get_power_of(unsigned int d, int base);

int ft_printf(const char *format, ...);

int ft_printf_s(t_flags flags, char *s);
int ft_printf_c(t_flags flags, int c);
int	ft_printf_d(t_flags flags, int d);
int	ft_printf_u(t_flags flags, unsigned int d);
int	ft_printf_x(t_flags flags, unsigned int d, char *base);
#endif