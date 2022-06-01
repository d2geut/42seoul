CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
HD_DIR = includes

libft.a : ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
	ar rscv libft.a $(SRC_DIR)/*.o 

ft_putchar.o : $(SRC_DIR)/ft_putchar.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_putchar.c -o $(SRC_DIR)/ft_putchar.o -I$(HD_DIR)/ft.h

ft_swap.o : $(SRC_DIR)/ft_swap.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_swap.c -o $(SRC_DIR)/ft_swap.o -I$(HD_DIR)/ft.h

ft_putstr.o : $(SRC_DIR)/ft_putstr.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_putstr.c -o $(SRC_DIR)/ft_putstr.o -I$(HD_DIR)/ft.h

ft_strlen.o : $(SRC_DIR)/ft_strlen.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_strlen.c -o $(SRC_DIR)/ft_strlen.o -I$(HD_DIR)/ft.h

ft_strcmp.o : $(SRC_DIR)/ft_strcmp.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_strcmp.c -o $(SRC_DIR)/ft_strcmp.o -I$(HD_DIR)/ft.h

.PHONY: all
all : libft.a

.PHONY: clean
clean :
	rm $(SRC_DIR)/*.o

.PHONY: fclean
fclean :
	rm $(SRC_DIR)/*.o libft.a

.PHONY: re
re :
	make fclean
	make all
