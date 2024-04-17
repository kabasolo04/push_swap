NAME = push_swap
CC = cc
LIBFT_LIB = src/libft/
LIBFT_FLAGS = -L src/libft/ -lft
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM		= rm -f

SRC =	src/main.c \
		src/data.c \
		src/sort.c \
		src/utils.c \
		src/moves.c \

OBJS = $(SRC:%.c=%.o)

all:	$(NAME)

.c.o:
		$(CC) -I includes/. $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@make -C $(LIBFT_LIB)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

clean:
		$(RM) */*.o

fclean:	clean
		$(RM) $(NAME)
		@make -C $(LIBFT_LIB) fclean

re:		fclean all

.PHONY : all clean fclean re