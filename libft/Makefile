# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 16:35:34 by dcastor           #+#    #+#              #
#    Updated: 2025/05/10 15:17:22 by dcastor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD

NAME = libft.a
OPTIONS = -c -I ./includes

SRCS_DIR = srcs/
BUILD_DIR = build/

SRCS = $(addprefix $(SRCS_DIR), \
	char/ft_isalpha.c \
	char/ft_isdigit.c \
	char/ft_isalnum.c \
	char/ft_isascii.c \
	char/ft_isprint.c \
	char/ft_toupper.c \
	char/ft_tolower.c \
	memory/ft_memset.c \
	memory/ft_bzero.c \
	memory/ft_memcpy.c \
	memory/ft_memmove.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_calloc.c \
	number/ft_abs.c \
	string/ft_strlen.c \
	string/ft_strlcpy.c \
	string/ft_strlcat.c \
	string/ft_strchr.c \
	string/ft_strrchr.c \
	string/ft_strncmp.c \
	string/ft_strnstr.c \
	string/ft_strdup.c \
	string/ft_substr.c \
	string/ft_strjoin.c \
	string/ft_strtrim.c \
	string/ft_strmapi.c \
	string/ft_striteri.c \
	utils/ft_split.c \
	utils/ft_atoi.c \
	utils/ft_itoa.c \
	utils/ft_itoa_base.c \
	utils/ft_strset.c \
	utils/ft_uitoa_base.c \
	utils/ft_uitoa.c \
	utils/quick_sort.c \
	output/ft_putchar_fd.c \
	output/ft_putstr_fd.c \
	output/ft_putendl_fd.c \
	output/ft_putnbr_fd.c \
	list/ft_lstsome.c \
	list/ft_lstnew.c \
	list/ft_lstadd_front.c \
	list/ft_lstsize.c \
	list/ft_lstlast.c \
	list/ft_lstadd_back.c \
	list/ft_lstdelone.c \
	list/ft_lstclear.c \
	list/ft_lstiter.c \
	list/ft_lstmap.c \
	validate/is_valid_number.c \
)

OBJS = $(patsubst  %.c, $(BUILD_DIR)%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	@ar rsc $(NAME) $(OBJS)
	@echo "[$(NAME)] Archive generated ✅"

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@echo "[$(NAME)] build directory created ✅"

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $@ $<
	@echo "[$(NAME)] Compiling $<"

clean:
	@rm -f $(OBJS) $(OBJ_BONUS)
	@echo "File objects cleaned 🧼"

fclean: clean
	@rm -f $(NAME)
	@echo "[$(NAME)] Everything has been cleaned 🧼"
	@echo

re: fclean all

.PHONY: all clean fclean re

-include  $(DEPS)
