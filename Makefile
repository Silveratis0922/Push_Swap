LIBFT = ./Libft/libft.a

NAME = push_swap

CC =  gcc

CFLAGS = -Wall -g3 -Wextra -Werror

SRC = main.c push_swap.c moves.c verif_overflow.c ft_sort_list.c algo.c struct_content.c write_action.c struct_cost_a.c count_move.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L./Libft -lft

$(LIBFT) :
	make -C Libft

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I . -I Libft

random_100 :
	seq 1 100 | sort -R | tr "\n" " "; echo

random_500 :
	seq 1 500 | sort -R | tr "\n" " "; echo

clean : 
	rm -f $(OBJ)
	make clean -C Libft

fclean : clean
	rm -f $(NAME)
	make fclean -C Libft

re : fclean all

.PHONY : all clean fclean re
