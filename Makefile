NAME	= push_swap
NAME_B	= checker
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

HEADER	= ./push_swap.h

SRC		= ./src/main.c\
		./src/utils/checker.c\
		./src/utils/checker_2.c\
		./src/utils/split.c\
		./src/utils/lst.c\
		./src/utils/string.c\
		./src/utils/sort.c\
		./src/utils/utils.c\
		./src/utils/free.c\
		./src/sort/sort_two_to_five.c\
		./src/sort/sort_utils.c\
		./src/sort/sort_more.c\
		./src/operations/swap.c\
		./src/operations/rotate.c\
		./src/operations/reverse.c\
		./src/operations/push.c

BONUS	= ./bonus/checker.c\
		./bonus/utils.c\
		./src/utils/split.c\
		./src/utils/lst.c\
		./src/utils/checker.c\
		./src/utils/checker_2.c\
		./src/utils/free.c\
		./src/utils/utils.c\
		./src/operations/swap.c\
		./src/operations/rotate.c\
		./src/operations/reverse.c\
		./src/operations/push.c\
		./src/utils/string.c

all: $(NAME)
$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

bonus: $(NAME_B)
$(NAME_B): $(BONUS) $(HEADER)
	$(CC) $(CFLAGS) $(BONUS) -o $(NAME_B)

clean:

fclean:
	$(RM) $(NAME_B) $(NAME)

re : fclean all

.PHONY: fclean clean all bonus