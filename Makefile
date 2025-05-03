CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -I includes -I libft -g

AR = ar
ARFLAGS = rcs

MAKE = make

RM = rm -f

NAME = libftprintf.a
LIB = libft.a
LIB_DIR = libft/

BUILD_DIR = build/

SRCS_DIR = srcs/
SRCS  = \
	ft_printf.c \
 	text_raw.c \
 	format.c \
 	format_validator.c \
 	printers.c \
 	parsers.c \

OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD_DIR)$(LIB) $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo
	@echo "[$(NAME)] Archive generated ✅"

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[$(NAME)] Compiling $<"

$(BUILD_DIR)$(LIB): $(LIB)
	$(MAKE) bonus -C libft

$(BUILD_DIR):
	@echo "\n"
	@mkdir -p $(BUILD_DIR)
	@echo "[$(NAME)] Creating build directory"

$(LIB):
	@if [ ! -d "$(LIB_DIR)" ]; then \
		git clone git@github.com:DylanC-Code/Libft.git $(LIB_DIR); \
	fi

bonus: all
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "[$(NAME)] Bonus successfully added to the archive 🎆"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) clean -C libft
	@echo "[$(NAME)] Cleaning object files 🧼"

fclean: clean
	@$(RM) $(NAME) $(BUILD_DIR)$(LIB)
	@$(MAKE) fclean -C libft
	@echo "[$(NAME)] Cleaning archive 🧼"

re: fclean all
	@echo "[$(NAME)] Rebuilding all"

rebonus: fclean bonus

test:
	~/francinette/tester.sh -m && ~/francinette/tester.sh -ms

test_bonus:
	~/francinette/tester.sh -b && ~/francinette/tester.sh -bs

main: all
	$(CC) -g  -O0 $(CFLAGS) $(OBJS) $(BUILD_DIR)$(LIB)

.PHONY: all clean fclean re

-include $(DEPS)
