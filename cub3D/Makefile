NAME = cub3d
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = prove.c
OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re