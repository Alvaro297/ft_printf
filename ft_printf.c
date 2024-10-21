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
		return (ft_print_char(va_arg(arg, int)));
	else if (param == '%')
		return (ft_print_char('%'));
	else if (param == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (param == 'p')
		return (ft_print_pbase(va_arg(arg,
					unsigned long int), "0123456789abcdef"));
	else if (param == 'd' || param == 'i')
		return (ft_printf_nbr(va_arg(arg, int)));
	else if (param == 'u')
		return (ft_print_ubase((unsigned long int)
				va_arg(arg, unsigned int), "0123456789"));
	else if (param == 'x')
		return (ft_print_base(va_arg(arg, int), "0123456789abcdef"));
	else if (param == 'X')
		return (ft_print_base(va_arg(arg, int), "0123456789ABCDEF"));
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
			ret = check_params(format[++i], arg);
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
/*
int main(void)
{
	int ret_ft;
    int ret_std;

    // Pruebas con ft_printf y printf, capturando los valores de retorno
    ret_ft = ft_printf("Probando enteros: %d\n", 42);
    ret_std = printf("Probando enteros: %d\n", 42);
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("Probando negativos: %d\n", -42);
    ret_std = printf("Probando negativos: %d\n", -42);
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Probando porcentajes: %%");
    ret_std = printf("Probando negativos: %%");
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("Probando cadenas: %s\n", "Hola, mundo!");
    ret_std = printf("Probando cadenas: %s\n", "Hola, mundo!");
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("Probando caracteres: %c\n", 'A');
    ret_std = printf("Probando caracteres: %c\n", 'A');
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("Probando hexadecimales: %x\git@vogsphere-v2.42madrid.com:vogsphere/intra-uuid-a6ff9b9c-98c5-4e61-9379-d4ad95ef274a-6138553-alvamart %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("Probando punteros: %p\n", (void*)main);
    ret_std = printf("Probando punteros: %p\n", (void*)main);
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("Probando unsigned: %u\n", 3000000000U);
    ret_std = printf("Probando unsigned: %u\n", 3000000000U);
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("Probando porcentaje: %%\n");
    ret_std = printf("Probando porcentaje: %%\n");
    printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);
    // Pruebas básicas con ft_printf
    ft_printf("Probando enteros: %d\n", 42);
    ft_printf("Probando negativos: %d\n", -42);
    ft_printf("Probando cadenas: %s\n", "Hola, mundo!");
    ft_printf("Probando caracteres: %c\n", 'A');
    ft_printf("Probando hexadecimales: %x\n", 255);
    ft_printf("Probando punteros: %p\n", (void*)main);
    ft_printf("Probando unsigned: %u\n", 3000000000U);
    ft_printf("Probando porcentaje: %%\n");

    // También puedes comparar con printf para verificar la salida
    printf("Comparando con printf:\n");
    printf("Probando enteros: %d\n", 42);
    printf("Probando negativos: %d\n", -42);
    printf("Probando cadenas: %s\n", "Hola, mundo!");
    printf("Probando caracteres: %c\n", 'A');
    printf("Probando hexadecimales: %x\n", 255);
    printf("Probando punteros: %p\n", (void*)main);
    printf("Probando unsigned: %u\n", 3000000000U);
    printf("Probando porcentaje: %%\n");

    return 0;
}
*/
