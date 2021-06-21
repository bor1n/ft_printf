#include "libft.h"

static void	ft_fill_array(int *array, int nmb)
{
	int	counter;

	counter = 9;
	while (nmb > 0)
	{
		array[counter] = nmb % 10;
		counter--;
		nmb /= 10;
	}
	while (counter >= 0)
	{
		array[counter] = -1;
		counter--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	array[10];
	int	counter;

	counter = 0;
	if (n == 0)
		ft_putstr_fd("0", fd);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n + -2 * n;
	}
	ft_fill_array(array, n);
	while (counter < 10)
	{
		if (array[counter] != -1)
			ft_putchar_fd((char)(array[counter] + 48), fd);
		counter++;
	}
}
