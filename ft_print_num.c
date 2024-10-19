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

int	ft_print_ubase(unsigned int nbr, char *base)
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
		len_printf += 1;
	}
	if (nbr >= len)
	{
		ft_putnbr_ubase(nbr / len, base);
		ft_putnbr_ubase(nbr % len, base);
	}
	return (len_printf);
}

int	ft_print_base(int nbr, char *base)
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
		len_printf += 1;
	}
	if (nbr < len)
	{
		c = base[nbr];
		write(1, &c, 1);
		len_printf += 1;
	}
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
	return (len_printf);
}

int	ft_printf_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nb < 0)
	{
		len += write(1, '-', 1);
		nb = -nb;
		len += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
	{
		nb += 48;
		len += write(1, &nb, 1);
	}
	return (len);
}
