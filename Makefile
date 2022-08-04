LIBFT = ./Libft/libft.a

NAME = push_swap

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c lst_rotate.c ft_lstrotate.c
        
#BONUS_SRC = 
            
OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${BONUS_SRC:.c=.o}


all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L./Libft -lft

$(LIBFT):
	 make -C Libft

.c.o:
	${CC} ${CFLAGS} -I . -I Libft -c $< -o ${<:.c=.o}

clean: 
	/bin/rm -f *.o
	/bin/rm -f */*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean bonus re
