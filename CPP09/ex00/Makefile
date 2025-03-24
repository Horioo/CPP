NAME = btc

CC = c++ -Wall -Werror -Wextra -std=c++98
RM = rm -f

FILES = main.cpp Span.cpp

SRCS = $(FILES)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(OBJ) -o $(NAME)
			@echo "$(NAME) created"	

clean:
				@$(RM) $(NAME)
				@echo "$(NAME) deleted"

fclean:
				@$(RM) $(NAME)
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:			start all fclean clean re