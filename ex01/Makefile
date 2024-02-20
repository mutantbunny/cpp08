CC = c++
CFLAGS = -Wall -Wextra -Werror -ggdb -std=c++98
RM = rm -f

NAME = ex01

SRCS = main.cpp Span.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = Span.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME)

re: fclean all