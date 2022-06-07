char	*is_byte(char *str)
{
	while (is_space(*(str)))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
		str++;
	return (str);
}

void	byte_error(char *str)
{

}
