#!/bin/sh

gcc -Wall -Wextra -Werror -c ./*.c
ar rscv libft.a ./*.o
