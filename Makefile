NAME_PS = push_swap
CHECKER = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_PS = ps/push_swap.c lst_funcs/ft_lstnew_ps.c lst_funcs/ft_lstadd_back_ps.c \
ps/ft_find_int_doubles.c lst_funcs/ft_lstlast_ps.c lst_funcs/ft_lstadd_front_ps.c \
lst_funcs/ft_lstsize.c ps/parser.c ps/instructions_a.c ps/instructions_b.c \
lst_funcs/ft_lstclear.c ps/small_numbers.c ps/indexes.c ps/sort.c ps/fill_stack_b.c \
ps/inctructions_both.c
SRC_CHECKER = check/checker_bonus.c check/execute_instr.c ps/parser.c \
ps/ft_find_int_doubles.c lst_funcs/ft_lstadd_back_ps.c\
lst_funcs/ft_lstnew_ps.c lst_funcs/ft_lstlast_ps.c lst_funcs/ft_lstadd_front_ps.c \
lst_funcs/ft_lstsize.c ps/instructions_a.c ps/instructions_b.c lst_funcs/ft_lstclear.c \
ps/inctructions_both.c
OBJ = $(SRC_PS:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
D_FILES = $(SRC_PS:.c=.d) $(SRC_CHECKER:.c=.d)

all : libmake $(NAME_PS)

$(NAME_PS) : $(OBJ)
		$(CC) $(FLAGS) libft.a $(OBJ) -o $@

libmake :
		cd ./libft && make
		cp ./libft/libft.a ./

bonus : libmake $(CHECKER)

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

.PHONY: all clean fclean re bonus libmake