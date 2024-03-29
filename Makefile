LIBFT = ./Libft/libft.a

NAME = push_swap

CC =  gcc

CFLAGS = -Wall -g3 -Wextra -Werror

SRC = main.c already_ordered.c verif_overflow.c moves.c ft_sort_list.c first_algo.c struct_content.c write_action.c struct_cost_a.c \
	count_move.c delete_lst.c final_algo.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L./Libft -lft

$(LIBFT) :
	make -C Libft

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I . -I Libft

random_100 :
	seq 1 50 | sort -R | tr "\n" " "; echo

random_500 :
	seq 1 500 | sort -R | tr "\n" " "; echo
test5 : $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l
test100 : $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500 : $(NAME)
	$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

clean : 
	rm -f $(OBJ)
	make clean -C Libft

fclean : clean
	rm -f $(NAME)
	make fclean -C Libft

re : fclean all

.PHONY : all clean fclean re
