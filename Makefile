NAME_PS = push_swap
CHECKER = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_PS = push_swap.c ft_lstnew_ps.c ft_lstadd_back_ps.c ft_find_int_doubles.c \
ft_lstlast_ps.c ft_lstadd_front_ps.c ft_lstsize.c parser.c instructions_a.c \
instructions_b.c ft_lstclear.c
SRC_CHECKER = checker_bonus.c parser.c ft_find_int_doubles.c ft_lstadd_back_ps.c\
ft_lstnew_ps.c ft_lstlast_ps.c ft_lstadd_front_ps.c get_next_line_bonus.c \
get_next_line_utils_bonus.c ft_lstsize.c instructions_a.c\
instructions_b.c ft_lstclear.c
OBJ = $(SRC_PS:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
D_FILES = $(SRC_PS:.c=.d) $(SRC_CHECKER:.c=.d)

all : libft.a $(NAME_PS)

$(NAME_PS) : $(OBJ)
		$(CC) $(FLAGS) libft.a $(OBJ) -o $@

libft.a :
		cd ./libft && make
		cp ./libft/libft.a ./

bonus : libft.a $(CHECKER)

$(CHECKER) : $(OBJ_CHECKER)
		$(CC) $(FLAGS) libft.a $(OBJ_CHECKER) -o $@

%.o : %.c
		$(CC) $(FLAGS) -c $? -o $@ -MD

clean :
		rm -f $(OBJ) $(OBJ_CHECKER)
		rm -f $(D_FILES)
		rm -f libft.a
		cd ./libft && make clean

fclean : clean
		rm -f $(NAME_PS) $(CHECKER)
		cd ./libft && rm -f libft.a

re : fclean all

.PHONY: all clean fclean re