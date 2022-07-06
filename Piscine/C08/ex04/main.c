#include <stdio.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int main()
{
	printf("\n============EX04, EX05============\n\n");
	t_stock_str	*strts;
	char	*av[3];

	*(av + 0) = "JEONGBLE";	
	*(av + 1) = "IS";
	*(av + 2) = "BOAAAAAAAA";
	strts = ft_strs_to_tab(3, av);
	printf("--------- output ---------\n");
	printf("JEONGBLE\n8\nJEONGBLE\nIS\n2\nIS\nBABO\n4\nBABO\n");
	printf("------ user  output ------\n");
	ft_show_tab(strts);
	printf("===============FIN===============\n\n");
}
