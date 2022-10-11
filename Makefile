
SERVER =	server
CLIENT =	client

SRC =		src/
SERVER_SRC = $(SRC)server.c
CLIENT_SRC = $(SRC)client.c

SERVER_OBJS = $(SRC)server.o
CLIENT_OBJS = $(SRC)client.o
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)

FLAGS =		-Werror -Wextra -Wall
CC = 		gcc

LIBFT_DIR = 		lib/Libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all:	$(SERVER) $(CLIENT)

%.o:%.c
	$(CC) $(FLAGS) $< -o $@
	
LIBFT:
	@make -C $(LIBFT_DIR)

PRINTF:
	@make -C $(PRINTF_DIR)

$(SERVER): LIBFT PRINTF $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_SRC) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): LIBFT PRINTF $(CLIENT_SRC)
	@$(CC) $(FLAGS) $(CLIENT_SRC) $(LIBFT) $(PRINTF) -o $(CLIENT)

clean:
		@rm -f	$(OBJS)
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(PRINTF_DIR)

fclean: clean
		@rm -f	$(SERVER) $(CLIENT)
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(PRINTF_DIR)

re:			fclean all

.PHONY: all clean fclean re
