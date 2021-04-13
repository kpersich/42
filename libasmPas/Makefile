NAME	=	libasm.a

SRCS	=	${wildcard srcs/*.s}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJ		=	${SRCS:.s=.o}

%.o		:	%.s
			nasm -f macho64 $<

$(NAME)	:	${OBJ}
			ar rcs ${NAME} ${OBJ}

all		:	$(NAME)

bot		:	all
			@git clone https://github.com/Tripouille/libasmTester.git bot
			@cd bot && make m
			@rm -rf bot
			@make fclean

test	:	all
			$(CC) $(CFLAGS) main.c $(NAME) -o test
			./test

clean	:
			rm -rf ${OBJ} ${BNS_OBJ}

fclean	:	clean
			rm -rf test
			rm -rf ${NAME} $(bonus)

re		:	fclean all

.PHONY	:	all bonus clean fclean re test
