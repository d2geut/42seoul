void	ft_putchar(char c);

void	rush00_2(int	i, int	j)
{
	if (i == 1 || i == x)
	{
		if (j == 1 || j == y)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('|');
		}
	}
	else if (j == 1 || j == y)
	{
		ft_putchar('-');
	}
	else
	{
		ft_putchar(' ')
	}
}

void	rush00_1(int	x, int	y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j <= y)
	{
		while (++i <= x)
		{
			rush00_2(i, j);
		}
		i = 0;
		ft_putchar('\n');
	}
}
