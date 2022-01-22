NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c
OBJ = $(SRC.c=.o)
D_FILES = $(SRC.c=.d)

all : $(NAME)

$(NAME) : create_libft $(OBJ)
		$(CC) $(FLAGS) $< -o $@

create_libft :
		cd ./libft && make
		cp libft.a ./

%.o : %.c
		$(CC) $(FLAGS) -c $< -o $@ -MD

clean :
		rm -f $(OBJ)
		cd ./libft && make clean

fclean : clean
		rm -f $(NAME)
		cd ./libft && rm -f libft.a

