NAME_SERVER 		= server
NAME_CLIENT			= client 

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f 

SOURCES_SERVER 	= main_server.c
SOURCES_CLIENT	= helpers.c main_client.c
OBJECTS_SERVER	= main_server.o
OBJECTS_CLIENT	= helpers.o main_client.o 

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJECTS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $^ 

$(NAME_CLIENT): $(OBJECTS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $^ 

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(OBJECTS_SERVER) $(OBJECTS_CLIENT)

fclean:
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(OBJECTS_SERVER) $(OBJECTS_CLIENT)

re: fclean all

.PHONY: all re clean fclean