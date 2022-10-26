SERVER		=	server
CLIENT		=	client

SERVER_BONUS	= 	server_bonus
CLIENT_BONUS	=	client_bonus

SRC			=	src/
SERVER_SRC	=	$(SRC)server.c
CLIENT_SRC	=	$(SRC)client.c

SERVER_BONUS_SRC	=	$(SRC)server_bonus.c
CLIENT_BONUS_SRC	=	$(SRC)client_bonus.c

SERVER_OBJS	=	$(SRC)server.o
CLIENT_OBJS	=	$(SRC)client.o

SERVER_BONUS_OBJS	=	$(SRC)server_bonus.o
CLIENT_BONUS_OBJS	=	$(SRC)client_bonus.o

OBJS		=	$(SERVER_OBJS) $(CLIENT_OBJS)
OBJS_BONUS	=	$(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

FLAGS		=	-Werror -Wextra -Wall
CC			=	gcc

LIBFT_DIR	=	lib/Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	lib/ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

all:	makelibs server client

$(SRC)%.o:$(SRC)%.c
	$(CC) $(FLAGS) -c $< -o $@

makelibs:
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)

bonus: makelibs server_bonus client_bonus

server: $(LIBFT) $(PRINTF) $(SERVER_OBJS)
	$(CC) $(FLAGS) $(SERVER_OBJS) $(LIBFT) $(PRINTF) -o $(SERVER)

client: $(LIBFT) $(PRINTF) $(CLIENT_OBJS)
	$(CC) $(FLAGS) $(CLIENT_OBJS) $(LIBFT) $(PRINTF) -o $(CLIENT)

server_bonus: $(LIBFT) $(PRINTF) $(SERVER_BONUS_OBJS)
	$(CC) $(FLAGS) $(SERVER_BONUS_OBJS) $(LIBFT) $(PRINTF) -o $(SERVER_BONUS)

client_bonus: $(LIBFT) $(PRINTF) $(CLIENT_BONUS_OBJS)
	$(CC) $(FLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) $(PRINTF) -o $(CLIENT_BONUS)

clean:
		@rm -rf	$(OBJS) $(OBJS_BONUS)
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(PRINTF_DIR)

fclean: clean
		@rm -rf	$(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(PRINTF_DIR)

re:		fclean all

.PHONY: all clean fclean re bonus
