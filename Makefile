NAME = webserv

CC = clang++

CFLAGS = -Werror -Wextra -Wall

SRCS = $(addprefix ./srcs/, \
		main.cpp)

OBJS = $(SRCS:.cpp=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
