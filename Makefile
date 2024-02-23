# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 14:08:18 by nholbroo          #+#    #+#              #
#    Updated: 2024/02/23 17:19:16 by nholbroo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=src/push_swap.c \
	src/small_sorts/sorting_five_numbers_utils.c \
	src/small_sorts/sorting_five_numbers.c \
	src/small_sorts/sorting_four_numbers.c \
	src/small_sorts/sorting_three_numbers.c \
	src/operations/a_sort_operations.c \
	src/operations/ab_sort_operations.c \
	src/operations/b_sort_operations.c \
	src/helper_functions/free_functions.c \
	src/helper_functions/ft_split.c \
	src/helper_functions/sorting_check.c \
	src/helper_functions/stack_find_desired_index.c \
	src/helper_functions/stack_init.c \
	src/helper_functions/stack_utils.c \
	src/helper_functions/standard_functions.c \
	src/error_handling/error_more_args.c \
	src/error_handling/error_one_arg.c \
	src/big_sort/push.c \
	src/big_sort/double_rotations.c \
	src/big_sort/find_median_and_currpos.c \
	src/big_sort/find_min_and_max_value.c \
	src/big_sort/set_pushcost.c \
	src/big_sort/set_target.c \
	src/big_sort/single_rotations.c \
	src/big_sort/sort.c \
	src/ft_printf/ft_printf.c \
	src/ft_printf/ft_putchar.c \
	src/ft_printf/ft_puthexa_lower.c \
	src/ft_printf/ft_puthexa_upper.c \
	src/ft_printf/ft_putnbr.c \
	src/ft_printf/ft_putpercent.c \
	src/ft_printf/ft_putptr.c \
	src/ft_printf/ft_putstr.c \
	src/ft_printf/ft_putuint.c \
	src/ft_printf/ft_strlen.c \

OBJ=$(patsubst src/%, build/%, $(SRC:.c=.o))
NAME=push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

build:	
		@if [ ! -d "build" ]; \
			then mkdir -p "build"; \
		fi

build/%.o: src/%.c
		@mkdir -p $(dir $@)
		@echo "Compiling \e[1;32m$(notdir $<)\e[0m"
		@$(CC) $(CFLAGS) -Iinc -c $< -o $@;

leaks: all
		@echo "\e[1;93mRunning Valgrind with double quotation marks\e[0m"
		@valgrind ./push_swap "$(shell seq 1 500 | shuf | tr '\n' ' ')" 2>&1 \
		| grep -A 9999999 "HEAP SUMMARY" | grep -B 9999999 "ERROR SUMMARY"
		@echo "\e[1;93mRunning Valgrind without double quotation marks\e[0m"
		@valgrind ./push_swap $(shell seq 1 500 | shuf | tr '\n' ' ') 2>&1 \
		| grep -A 9999999 "HEAP SUMMARY" | grep -B 9999999 "ERROR SUMMARY"

test_operations: all
		@echo "\e[1;93mRunning test with 5 random values\e[0m"
		@./push_swap "$(shell seq 1 5 | shuf | tr '\n' ' ')" | wc -l
		@echo "\e[1;93mRunning test with 100 random values\e[0m"
		@./push_swap "$(shell seq 1 100 | shuf | tr '\n' ' ')" | wc -l
		@echo "\e[1;93mRunning test with 500 random values\e[0m"
		@./push_swap "$(shell seq 1 500 | shuf | tr '\n' ' ')" | wc -l

test_sort: all checker_linux
		@RANDOM_SEQUENCE="$(shell seq 1 5 | shuf | tr '\n' ' ')"; \
		echo "\e[1;93mRunning test with 5 random values\e[0m"; \
		RESULT=$$(./push_swap "$$RANDOM_SEQUENCE" | \
		./checker_linux "$$RANDOM_SEQUENCE"); \
		if [ "$$RESULT" = "OK" ]; then \
			echo "\e[92mOK\e[0m"; \
		else \
			echo "\e[91mKO\e[0m"; \
		fi

		@RANDOM_SEQUENCE="$(shell seq 1 100 | shuf | tr '\n' ' ')"; \
		echo "\e[1;93mRunning test with 100 random values\e[0m"; \
		RESULT=$$(./push_swap "$$RANDOM_SEQUENCE" | \
		./checker_linux "$$RANDOM_SEQUENCE"); \
		if [ "$$RESULT" = "OK" ]; then \
			echo "\e[92mOK\e[0m"; \
		else \
			echo "\e[91mKO\e[0m"; \
		fi

		@RANDOM_SEQUENCE="$(shell seq 1 500 | shuf | tr '\n' ' ')"; \
		echo "\e[1;93mRunning test with 500 random values\e[0m"; \
		RESULT=$$(./push_swap "$$RANDOM_SEQUENCE" | \
		./checker_linux "$$RANDOM_SEQUENCE"); \
		if [ "$$RESULT" = "OK" ]; then \
			echo "\e[92mOK\e[0m"; \
		else \
			echo "\e[91mKO\e[0m"; \
		fi

test_errors: all
		@echo "\e[1;93mRunning test with duplicates\e[0m"
		@echo "Input: 1 2 3 3 4"
		@./push_swap "1 2 3 3 4" || true
		@echo "\e[1;93mRunning test with a value bigger than an integer\e[0m"
		@echo "Input: 2147483648"
		@./push_swap "2147483648" || true
		@echo "\e[1;93mRunning test with non-integer characters\e[0m"
		@echo "Input: 1 2 a b c"
		@./push_swap "1 2 a b c" || true

clean:
	@rm -f build/*.o
	@rm -f build/*/*.o
	@echo "\e[1;32mAll object files removed\e[0m"

fclean:
	@rm -rf build
	@rm -f $(NAME)
	@echo "\e[1;32mBuild directory and executable removed\e[0m"

re: fclean all

.PHONY: all clean fclean re
