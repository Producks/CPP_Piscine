NAME = HarlFilter

CC = c++

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC =	main.cpp \
		Harl.cpp

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