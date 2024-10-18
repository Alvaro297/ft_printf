/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 10:01:35 by alvamart          #+#    #+#             */
/*   Updated: 2024-10-18 10:01:35 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_params(char param, va_list arg)
{
	if (param == 'c')
		return ft_print_char(va_arg(arg, char));
	else if (param == '%')
		return ft_print_char('%');
	else if (param == 's')
		return ft_print_str(va_arg(arg, char *));
	else if (param == 'p')
	{
		write(1, "0x", 2);
		return 2 + ft_print_ubase(va_arg(arg, unsigned long int), "0123456789abcdef");
	}
	else if (param == 'd' || param == 'i')
		return ft_printf_itoa(va_arg(arg, int));
	else if (param == 'u')
		return ft_print_ubase(va_arg(arg, unsigned int), "0123456789");
	else if (param == 'x')
		return ft_print_base(va_arg(arg, int), "0123456789abcdef");
	else if (param == 'X')
		return ft_print_base(va_arg(arg, int), "0123456789ABCDEF");
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;
	int		ret;

	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else
		{
			i++;
			ret = check_params(format[i], arg);
			if (ret > 0)
				len += ret;
			else
				i--;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
