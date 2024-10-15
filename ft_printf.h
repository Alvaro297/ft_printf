#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int	check_params(char param, va_list arg);
//UTILS STRINGS//
int	ft_print_char(char c);
int	ft_print_str(char *str);
//******//
//UTILS NUMS//
int	ft_print_base16(void *ptr,char *base);

//******//
#endif