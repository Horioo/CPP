NAME = Intern

CC = c++ -Wall -Werror -Wextra -std=c++98
RM = rm -f

FILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

SRCS = $(FILES)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(OBJ) -o $(NAME)
			@echo "$(NAME) created"	

fclean:
				@$(RM) $(NAME)
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:			start all fclean re