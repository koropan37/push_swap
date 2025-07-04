# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 15:34:26 by skimura           #+#    #+#              #
#    Updated: 2025/07/04 16:56:30 by skimura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
BONUS 		= checker

SRC 		= \
				src/01_main.c \
				src/02_parse.c \
				src/02.1_parse_args.c \
				src/02.2_parse_utils.c \
				src/03_solve.c \
				src/03.1_sort_under_five.c \
				src/03.2_sort_utils.c \
				src/04_list.c \
				src/04.1_create_list.c \
				src/04.2_compress_list.c \
				src/04.3_ft_qsort.c \
				src/05_lis.c \
				src/06_push_to_b.c \
				src/07_push_to_a.c \
				src/07.1_rotate_cost.c \
				src/cmd_p.c \
				src/cmd_p_helper.c \
				src/cmd_r.c \
				src/cmd_rr.c \
				src/cmd_r_rr_s_helper.c \
				src/cmd_s.c

BONUS_SRC 	= \
				bonus/checker_bonus.c \
				bonus/cmd_r_bonus.c \
				bonus/cmd_rr_bonus.c \
				bonus/cmd_s_p_bonus.c \

OBJS        = $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)
OBJS_NO_MAIN = $(filter-out src/01_main.o, $(OBJS))

INC_DIR		= include
LIBFT_DIR   = mylibft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

CC	 		= cc
CFLAGS 		= -Wall -Wextra -Werror
RM			= rm -f
INCLUDES    = -I . -I $(LIBFT_DIR) -I$(INC_DIR)
MAKEFLAGS 	+= --no-print-directory

# color
RESET   = \033[0m
BOLD    = \033[1m
BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m

.PHONY: all clean fclean re bonus

all: $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo  "$(BOLD)$(GREEN)[INFO]$(CYAN) Building $(WHITE)$(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB)  $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)[OK]$(BLUE) Build completed!$(RESET)"

bonus: $(BONUS)
$(BONUS): $(LIBFT_LIB) $(BONUS_OBJS) $(OBJS_NO_MAIN)
	@echo  "$(BOLD)$(GREEN)[INFO]$(CYAN) Building bonus $(WHITE)$(NAME)..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_NO_MAIN) $(LIBFT_LIB)  $(INCLUDES) -o $(BONUS)
	@echo "$(GREEN)[OK]$(BLUE) Build completed!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo  "$(BOLD)$(YELLOW)[INFO]$(MAGENTA) cleaning $(NAME)..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)[DONE]$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(BONUS)
	@echo "$(BOLD)$(YELLOW)[DELETE]$(RED)All clean $(NAME)$(RESET)"

test:
	@if [ ! -d "push_swap_tester" ]; then \
		git clone https://github.com/nafuka11/push_swap_tester.git; \
	fi

#chmod 777 checker
#cd push_swap_tester
#python3 push_swap_tester.py -l 100
#python3 push_swap_tester.py -l 500

re: fclean all
