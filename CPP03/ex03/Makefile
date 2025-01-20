NAME = DiamondTrap

CC = c++ -Wall -Werror -Wextra -Wno-shadow -std=c++98
RM = rm -f

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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