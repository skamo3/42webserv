NAME = webserv

CC = clang++

CFLAGS = -g -Werror -Wextra -Wall

SRCSDIR = ./srcs/

INCDIR = ./includes/

SRCS = $(addprefix $(SRCSDIR), \
		Configuration.cpp Server.cpp Location.cpp \
		Exception.cpp WebService.cpp \
		main.cpp)

OBJS = $(SRCS:.cpp=.o)

.PHONY : all clean fclean re

%.o: %.cpp
	$(CC) $(CFLAG) -I$(INCDIR) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
