NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

LIB = ar -rc

RAN = ranlib

SRCS = 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

%.o: %.c
	${CC} ${CFLAGS} $<

$(NAME): ${OBJS}
	${LIB} ${NAME} ${OBJS}
	${RAN} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ${OBJS}

re: fclean all

.PHONY: all bonus clean fclean re
