/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 10:01:51 by alvamart          #+#    #+#             */
/*   Updated: 2024-10-18 10:01:51 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_print_ubase(unsigned long int nbr, char *base)
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
		ft_putnbr_ubase(nbr / len, base);
		ft_putnbr_ubase(nbr % len, base);
	}
	return (len_printf);
}

int ft_print_base(unsigned long int nbr, char *base)
{
	int		len_printf;
	int		len;
	char	c;

	len = ft_strlen(base);
	len_printf = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, '-', 1);
		len_printf+= 1;
	}
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

int	ft_printf_itoa(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}