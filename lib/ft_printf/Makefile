NAME =		libftprintf.a

SRCS =		src/ft_check.c src/ft_printf.c src/ft_putchar.c src/ft_putlower.c src/ft_putnbr.c src/ft_putpointer.c src/ft_putstr.c src/ft_putui.c src/ft_putupper.c src/ft_protect.c

OBJS =		$(SRCS:.c=.o)

FLAGS =		-Werror -Wextra -Wall -c

CC = 		gcc

LIBR = 		lib/ft_printf.h

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m

all:		$(NAME)

%.o: %.c $(LIBR)
	@$(CC) $(FLAGS) $< -o $@
	@printf "\r⚙️  $(GRAY) ${CC} ${CFLAGS} -I./ -c $< -o $(DEF_COLOR)"

$(NAME):	$(OBJS) $(LIBR)
			@printf "\n"
			@ar -rcs $(NAME) $^
clean:
			@rm -f	$(OBJS)

fclean:		clean
			@rm -f	$(NAME)

re:			fclean all

.PHONY: all clean fclean re
