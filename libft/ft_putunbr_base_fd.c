#include "libft.h"

int	ft_check_characters(char *base)
{
	char	*pointer;

	if (*base == 0)
		return (1);
	if (*(base + 1) == 0)
		return (1);
	while (*base)
	{
		pointer = base + 1;
		while (*pointer)
		{
			if (*pointer == *base)
				return (1);
			pointer++;
		}
		if (*base == '+' || *base == '-' || *base <= 31)
			return (1);
		base++;
	}
	return (0);
}

void	print_number(unsigned long nbr, char *base, int length, int fd)
{
	unsigned long	index_of_symbol;

	if (nbr != 0 && (nbr / length != 0))
		print_number(nbr / length, base, length, fd);
	index_of_symbol = nbr % length;
	ft_putchar_fd(base[index_of_symbol], fd);
}

void	ft_putunbr_base_fd(unsigned long nbr, char *base, int fd)
{
	int		length;

	if (ft_check_characters(base))
		return ;
	length = (int)ft_strlen(base);
	print_number(nbr, base, length, fd);
}
