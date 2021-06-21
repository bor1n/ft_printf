#include "libft.h"

static void	ft_fill_array(int *array, unsigned int n)
{
	int	counter;

	counter = 9;
	while (n > 0)
	{
		array[counter] = n % 10;
		counter--;
		n /= 10;
	}
	while (counter >= 0)
	{
		array[counter] = -1;
		counter--;
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	int	array[10];
	int	counter;

	counter = 0;
	if (n == 0)
		ft_putstr_fd("0", fd);
	ft_fill_array(array, n);
	while (counter < 10)
	{
		if (array[counter] != -1)
			ft_putchar_fd((char)(array[counter] + 48), fd);
		counter++;
	}
}
