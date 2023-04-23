NAME = brainzzz

CC = c++

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = 	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
		$(RM) ${OBJS}

fclean:clean
		$(RM) $(NAME)

re:fclean all

.PHONY: all clean re