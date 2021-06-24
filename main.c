#include "includes/ft_printf.h"


int main() {
//	char *format_x = "%5.10X";
//	int x = 15;
//	int printf_d = printf(format_x, x);
//	ft_printf("!");
//	int my_printf_d = ft_printf(format_x, x);
//	ft_printf("!");

//	char *format_u = "%u";
//	int u = -1;
//	int printf_d = printf(format_u, u);
//	ft_printf("!");
//	int my_printf_d = ft_printf(format_u, u);
//	ft_printf("!");

	char *format_d = "%.1d";
	int d = -11;
	int printf_d = printf(format_d, d);
	ft_printf("!");
	int my_printf_d = ft_printf(format_d, d);
	ft_printf("!");

//	char *format_c = "%-10c";
//	char c = 't';
//	int print_c = printf(format_c, c);
//	ft_printf("!");
//	int my_print_c = ft_printf(format_c, c);
//	ft_printf("!\n");

//	char *format = "%.*s";
//	char *a = 0;
//    int print = printf(format, -3,a);
//	ft_printf("!");
//	int my_print = ft_printf(format, -3, a);
//	ft_printf("!");
	return (0);
}
