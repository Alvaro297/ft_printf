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
		write(1, '0x', 2);
		return 2 + ft_print_base16(va_arg(arg, unsigned long), "0123456789abcdef");
	}
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
