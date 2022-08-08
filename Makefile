LIBFT = ./Libft/libft.a

NAME = push_swap

CC =  gcc

CFLAGS = -Wall -g3 #-Wextra -Werror

SRC = push_swap.c ft_lstswap.c lst_rotate.c lst_reverse_rotate.c lst_push.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L./Libft -lft

$(LIBFT) :
	make -C Libft

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I . -I Libft

clean : 
	rm -f $(OBJ)
	make clean -C Libft

fclean : clean
	rm -f $(NAME)
	make fclean -C Libft

re : fclean all

.PHONY : all clean fclean re
