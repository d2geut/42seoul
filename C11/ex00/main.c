#include <stdio.h>
#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int));
void	intmin2(void)
{
	char	*ex;
	ex = "-2147483648";
	write(1, ex, 11);
}
void	ft_putnbr22(int nb)
{
	int		i;
	char	arr[10];
	if (nb == -2147483648)
		intmin2();
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		i = 0;
		while (nb > 0)
		{
			arr[i] = '0' + nb % 10;
			nb /= 10;
			i ++;
		}
		while (-- i >= 0)
			write(1, arr + i, 1);
	}
}

int main()
{
	printf("\n===============EX00===============\n\n");
	printf("0123456789\n");
	int	tab[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ft_foreach(tab, 10, &ft_putnbr22);

	return 0;
}
