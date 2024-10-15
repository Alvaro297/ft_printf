#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void ft_print_base16(unsigned long nbr, char *base)
{
	int		len_printf;
	int		len;
	char	c;

	len = ft_strlen(base);
	len_printf = 0;
	if (nbr < len)
	{
		c = base[nbr];
		write(1, &c, 1);
		len_printf+= 1;
	}
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
	return (len_printf);
}
