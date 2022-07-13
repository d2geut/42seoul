#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	char 			*str;
	struct s_list	*next;
}	t_list;

void	do_free(char *str)
{
	free(str);
	str = NULL;
}

int main()
{
	t_list	*lst;
	char	*str;

	lst = (t_list *)malloc(sizeof(t_list));
	str = (char *)malloc(sizeof(char) * 1);
	lst->next = NULL;
	lst->str = str;
	do_free(lst->str);
	// free(lst->str);
	// lst->str = NULL;
	free(lst);
	return (0);
}