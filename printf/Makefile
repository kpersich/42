NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_lib.c ft_lib2.c parse.c process.c process2.c
OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

	
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
