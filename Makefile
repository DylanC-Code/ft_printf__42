CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -I includes -I libft

AR = ar
ARFLAGS = rcs

MAKE = make

RM = rm -f

NAME = libftprintf.a

BUILD_DIR = build/

SRCS_DIR = srcs/
SRCS  = ft_printf.c

OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD_DIR)libft.a $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo
	@echo "[$(NAME)] Archive generated ✅"

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[$(NAME)] Compiling $<"

$(BUILD_DIR)libft.a:
	$(MAKE) rebonus -C libft

$(BUILD_DIR):
	@echo "\n"
	@mkdir -p $(BUILD_DIR)
	@echo "[$(NAME)] Creating build directory"

bonus: all
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "[$(NAME)] Bonus successfully added to the archive 🎆"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) clean -C libft
	@echo "[$(NAME)] Cleaning object files 🧼"

fclean: clean
	@$(RM) $(NAME) $(BUILD_DIR)libft.a
	@$(MAKE) fclean -C libft
	@echo "[$(NAME)] Cleaning archive 🧼"

re: fclean all
	@echo "[$(NAME)] Rebuilding all"

rebonus: fclean bonus

test:
	~/francinette/tester.sh -m && ~/francinette/tester.sh -ms

test_bonus:
	~/francinette/tester.sh -b && ~/francinette/tester.sh -bs

.PHONY: all clean fclean re

-include $(DEPS)
