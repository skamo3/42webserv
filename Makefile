NAME = webserv

CC = clang++

CFLAGS = -Werror -Wextra -Wall

SRCSDIR = ./srcs/

INCDIR = ./includes/

SRCS = $(addprefix $(SRCSDIR), \
		Configuration.cpp ServerConfig.cpp Location.cpp \
		Exception.cpp WebService.cpp \
		main.cpp)

OBJS = $(SRCS:.cpp=.o)

.PHONY : all clean fclean re

%.o: %.cpp
	$(CC) $(CFLAG) -I$(INCDIR) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) -o $(NAME)
	./webserv default.nginx

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
