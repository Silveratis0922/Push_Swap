NAME = push_swap.a

CC =  gcc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : all bonus clean fclean re
