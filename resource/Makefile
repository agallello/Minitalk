CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_CLIENT = minitalk_client.c
SRC_SERVER = minitalk_server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

.PHONY: all clean fclean re

all: client server

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(RM) client server

re: fclean all

