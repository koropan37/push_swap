# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 15:34:26 by skimura           #+#    #+#              #
#    Updated: 2025/06/02 17:22:30 by skimura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

SRCS 		= \
				src/ft_push_swap.c\

OBJS        = $(SRCS:.c=.o)

INC_DIR		= include
LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

CC	 		= cc
CFLAGS 		= -Wall -Wextra -Werror
RM			= rm -f
AR          = ar
ARFLAGS     = rcs
INCLUDES    = -I . -I $(LIBFT_DIR) -I$(INC_DIR)
MAKEFLAGS 	+= --no-print-directory

# color
BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo  "$(BOLD)$(GREEN)[INFO]$(CYAN) Building $(WHITE)$(NAME)..."
	@cp $(LIBFT_LIB) $@
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "$(GREEN)[OK]$(BLUE) Build completed!"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo  "$(BOLD)$(YELLOW)[INFO]$(MAGENTA) cleaning $(NAME)..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
	@echo "$(RED)[DONE]$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BOLD)$(YELLOW)[DELETE]$(RED)All clean $(NAME)$(RESET)"

re: fclean all
