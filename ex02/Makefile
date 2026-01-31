NAME = Bureaucrat
CXX = c++ 
CXXFLAGS =  -Wall -Werror -Wextra -std=c++98
SRCS = Bureaucrat.cpp AForm.cpp main.cpp ShrubberyCreationForm.cpp 	RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.shrubbery

re: fclean all

.PHONY: all clean re fclean
