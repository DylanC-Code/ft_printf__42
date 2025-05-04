CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -I includes -I libft -g

AR = ar
ARFLAGS = rcs

MAKE = make

RM = rm -rf

NAME = libftprintf.a
LIB = libft.a
LIB_DIR = libft/

BUILD_DIR = build/

SRC_DIR = srcs/
SRCS  = $(addprefix $(SRC_DIR), \
	ft_printf.c \
	text_raw.c \
	format.c \
	transformers/sign_transformer.c \
	transformers/precision_transformer.c \
	validators/validators.c \
	validators/types_validators.c \
	validators/format_validator.c \
	parsers/parsers.c \
	parsers/flag_parsers.c \
	parsers/width_parser.c \
	parsers/precision_parser.c \
	parsers/types/int_parsers.c \
	parsers/types/types_parsers.c \
	printers/printers.c \
	printers/int_printers.c \
	printers/utils_printers.c \
)

OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD_DIR)$(LIB) $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo
	@echo "[$(NAME)] Archive generated ✅"

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
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
	@$(RM) $(BUILD_DIR)
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
