# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 10:34:56 by skimura           #+#    #+#              #
#    Updated: 2025/06/13 20:33:22 by skimura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = \
	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
	libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c \
	libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
	libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c \
	libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c \
	libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
	libft/ft_strcmp.c libft/ft_strcspn.c libft/ft_strspn.c \
	libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c \
	libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c \
	libft/ft_lstmap.c\
	printf/ft_printf.c printf/ft_printf_str.c printf/ft_printf_number.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c


OBJS = $(SRCS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I./mylibft/include

AR = ar rcs
MAKEFLAGS += --no-print-directory

INCLUDES = -I include

ifdef BONUS
ALL_OBJS=$(OBJS) $(BOBJS)
else
ALL_OBJS=$(OBJS)
endif

BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m

all: $(NAME)

$(NAME): $(OBJS)
	@echo  "$(GREEN)[INFO]$(CYAN) Building $(WHITE)$(NAME)..."
	@$(AR) $(NAME) $(OBJS)
	@echo  "$(GREEN)[OK]$(BLUE) Build completed!"

bonus:
	@$(MAKE) BONUS=1
	@echo "bonus"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BOBJS)
	@echo "$(RED)[DONE]$(RESET)"


fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)[DELETE]$(RED)All clean $(NAME)"

re: fclean all

.PHONY: all clean fclean re bonus
