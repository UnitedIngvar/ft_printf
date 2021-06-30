SRCS		=		src/ft_parse_args.c src/ft_printf.c src/ft_strfuncs.c src/ft_uItoa.c \
					src/ft_make_space.c

OBJS		=		${SRCS:.c=.o}

HEADER		=		includes/ft_printf.h

NAME		=		libftprintf.a

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra

AR			=		ar

RM			=		rm -f

LIBFT		=		libft

ARFLAGS		=		rc

%o: %c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -include ${HEADER}

$(NAME):		${LIBFT} ${OBJS}
				ar rc libft/libft.a ${OBJS}
				cp libft/libft.a ${NAME}
				gcc src/main.c ${NAME}

all:			$(NAME)

clean:	
		${RM} ${OBJS} ${NAME}

$(LIBFT):
				make -C libft

.PHONY: all clean fclean re $(LIBFT)
