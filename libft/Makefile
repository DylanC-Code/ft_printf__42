CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g

NAME = libft.a
OPTIONS = -c -I.

BUILD_DIR = build/
# OUTPUT = ../$(BUILD_DIR)/$(NAME)

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_abs.c \
	ft_strset.c \
	ft_itoa_base.c \
	ft_uitoa.c \
	ft_uitoa_base.c \

OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.c=.o))

SRCS_BONUS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

OBJS_BONUS = $(addprefix $(BUILD_DIR), $(SRCS_BONUS:.c=.o))

DEPS = $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	@echo
	@ar rsc $(NAME) $(OBJS)
	@echo "[$(NAME)] Archive generated ✅"
	@echo


$(BUILD_DIR)%.o: %.c
	@$(CC) $(CFLAGS) $(OPTIONS) $< -o $@
	@echo "[$(NAME)] Compiling $<"

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@echo "[$(NAME)] Creating build directory"

bonus: all $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)
	@echo "[$(NAME)] Bonus successfully added to the archive 🎆"
	@echo

clean:
	@echo
	@rm -f $(OBJS) $(OBJS_BONUS) $(DEPS)
	@echo "[$(NAME)] File objects cleaned 🧼"

fclean: clean
	@rm -f $(NAME)
	@echo "[$(NAME)] Everything has been cleaned 🧼"
	@echo

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re

-include  $(DEPS)
