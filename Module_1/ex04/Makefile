NAME = sed

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

TESTER = ./sed Makefile = 69

SRC =	main.cpp 

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
		$(RM) ${OBJS}

fclean:clean
		$(RM) $(NAME)

re:fclean all

tester:re
		$(TESTER)

.PHONY: all clean re