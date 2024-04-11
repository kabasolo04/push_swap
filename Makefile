NAME = push_swap
CC = cc
LIBFT_LIB = libft/
LIBFT_FLAGS = -L libft/ -lft
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM		= rm -f

SRC =	srcs/main.c \
		srcs/data.c \
		srcs/sort.c \
		srcs/utils.c \
		srcs/moves.c \

OBJS = $(SRC:%.c=%.o)

all:	$(NAME)

.c.o:
		$(CC) -I includes/. $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		make -C $(LIBFT_LIB)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

clean:
		$(RM) */*.o
		$(RM) $(OBJS)
		make -C $(LIBFT_LIB) clean

fclean:	clean
		$(RM) $(NAME)
		make -C $(LIBFT_LIB) fclean

re:		fclean all

.PHONY : all clean fclean re