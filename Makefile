NAME_PS = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_PS = push_swap.c
OBJ = $(SRC_PS:.c=.o)
D_FILES = $(SRC_PS:.c=.d)

all : $(NAME_PS)

$(NAME_PS) : $(OBJ)
		$(CC) $(FLAGS) libft.a $< -o $@

#libft.a :
#		cd ./libft && make
#		cp ./libft/libft.a ./

%.o : %.c
		cd ./libft && make
		cp ./libft/libft.a ./
		$(CC) $(FLAGS) -c $< -o $@ -MD

clean :
		rm -f $(OBJ)
		rm -f libft.a
		cd ./libft && make clean

fclean : clean
		rm -f $(NAME_PS)
		cd ./libft && rm -f libft.a

