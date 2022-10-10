SERVER =	src/server.c

CLIENT =	src/client.c

OBJS =		$(SRCS:.c=.o)

FLAGS =		-Werror -Wextra -Wall -c

CC = 		gcc

LIBR = 		lib/ft_printf.h

all:		$(NAME)

%.o: %.c $(LIBR)
	$(CC) $(FLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBR)
			@ar -rcs $(NAME) $^
clean:
			@rm -f	$(OBJS)

fclean:		clean
			@rm -f	$(NAME)

re:			fclean all

.PHONY: all clean fclean re
