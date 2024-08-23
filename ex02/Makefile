NAME = account

CC = g++ -Wall -Werror -Wextra -std=c++98
RM = rm -f

FILES = tests.cpp Account.cpp

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