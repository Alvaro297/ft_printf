#Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a
SRCS = ft_printf.c ft_print_num.c ft_printf_strings.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#Eliminamos los archivos .o generados
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = clean all re test