NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_lib.c ft_printf.c parse.c process.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
