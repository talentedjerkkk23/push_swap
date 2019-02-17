SRC_CHECKER = checker_src/checker.c

SRC_PROGRAM = program/push_swap.c program/stack.c

HEAD = push_swap.h libft/libft.h

TEST_NAME = push_swap

CHECKER_NAME = checker

NAME = push_swap

RUN_CC = clang

CC = gcc

# FLAGS = -Wall -Wextra -Werror

LIB_SRC = libft

OBJECTS = $(SRC:.c=.o)

.PHONY: all clean fclean re checker push_swap

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	@make -C $(LIB_SRC)
	$(CC) -O3 $(FLAGS) $(SRC_CHECKER) -L libft -lft -o $(CHECKER_NAME)
	$(CC) -O3 $(FLAGS) $(SRC_PROGRAM) -L libft -lft -o $(NAME)

#clean: $(CLEAN_SUB_DIR)

clean:
	rm -f *.o
	@$(MAKE) -C $(LIB_SRC) clean

run:
	$(RUN_CC) -O3 $(SRC) main.c -L libft -lft -o $(NAME)

debug:
	$(RUN_CC) -g -O3 $(SRC) main.c -L libft -lft -o $(NAME)

fclean: clean
	@$(MAKE) -C $(LIB_SRC) fclean
	rm -rf $(NAME)

re_debug: debug

re: fclean all

