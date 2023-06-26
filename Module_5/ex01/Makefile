NAME = bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC =	main.cpp \
			Bureaucrat.cpp \
			Form.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
		$(RM) ${OBJS}

fclean:clean
		$(RM) $(NAME)

re:fclean all

run:all
	./$(NAME)

leak:all
	 valgrind --leak-check=yes ./$(NAME)

.PHONY: all clean re fclean run leak