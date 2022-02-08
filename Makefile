NAME_PS = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRC_PS = push_swap.c ft_lstnew_ps.c ft_lstadd_back_ps.c ft_find_int_doubles.c \
ft_lstlast_ps.c ft_lstadd_front_ps.c ft_lstsize.c
OBJ = $(SRC_PS:.c=.o)
D_FILES = $(SRC_PS:.c=.d)

all : libft.a $(NAME_PS)

$(NAME_PS) : $(OBJ)
		$(CC) $(FLAGS) libft.a $(OBJ) -o $@

libft.a :
		cd ./libft && make
		cp ./libft/libft.a ./

%.o : %.c
		$(CC) $(FLAGS) -c $? -o $@ -MD

clean :
		rm -f $(OBJ)
		rm -f $(D_FILES)
		rm -f libft.a
		cd ./libft && make clean

fclean : clean
		rm -f $(NAME_PS)
		cd ./libft && rm -f libft.a

re : fclean all

.PHONY: all clean fclean re