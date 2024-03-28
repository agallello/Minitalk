CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_CLIENT = minitalk_client.c
SRC_SERVER = minitalk_server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
LIBFT = libft.a

.PHONY: all clean fclean re

all: client server

client: $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

server: $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	@# Compile libft if needed, adjust the command as per your libft structure
	@make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@make -C libft/ clean

fclean: clean
	$(RM) client server
	@make -C libft/ fclean

re: fclean all
