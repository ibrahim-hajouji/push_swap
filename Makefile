NAME = push_swap
NAME2 = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
		big_stack.c \
		check.c \
		error.c \
		fill.c \
		push.c \
		range.c \
		reverse_rotate.c \
		rotate.c \
		small_stack.c \
		swap.c \
		utils.c \
		utils2.c \

SRCS2 = get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		checker_bonus.c \
		checker_utils_bonus.c \
		check.c \
		error.c \
		fill.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		utils.c \
		utils2.c \

OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME2) : $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

%.o: %.c push_swap.h checker_bonus.h get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME2)

clean :
	rm -f $(OBJS) $(OBJS2)

fclean : clean
	rm -f $(NAME) $(NAME2)

re : fclean all

.PHONY: all clean fclean re bonus