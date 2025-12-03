CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp Form.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)
