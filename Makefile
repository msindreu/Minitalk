SERVER		=	server
CLIENT		=	client

SRC			=	src/
SERVER_SRC	=	$(SRC)server.c
CLIENT_SRC	=	$(SRC)client.c

SERVER_OBJS	=	$(SRC)server.o
CLIENT_OBJS	=	$(SRC)client.o
OBJS		=	$(SERVER_OBJS) $(CLIENT_OBJS)

FLAGS		=	-Werror -Wextra -Wall
CC			=	gcc

LIBFT_DIR	=	lib/Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	lib/ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

all:	makelibs server client

(SRC)%.o:$(SRC)%.c
	$(CC) $(FLAGS) -c $< -o $@
	
makelibs:
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)

server: $(LIBFT) $(PRINTF) $(SERVER_OBJS)
	$(CC) $(FLAGS) $(SERVER_OBJS) $(LIBFT) $(PRINTF) -o $(SERVER)

client: $(LIBFT) $(PRINTF) $(CLIENT_OBJS)
	$(CC) $(FLAGS) $(CLIENT_OBJS) $(LIBFT) $(PRINTF) -o $(CLIENT)

clean:
		@rm -rf	$(OBJS)
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(PRINTF_DIR)

fclean: clean
		@rm -rf	$(SERVER) $(CLIENT)
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(PRINTF_DIR)

re:		fclean all

.PHONY: all clean fclean re
