CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
HEADER = ft_printf.h
RM = rm -rf
AR = ar -rcs

SRC =	ft_printf.c ft_printf_utiles.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
