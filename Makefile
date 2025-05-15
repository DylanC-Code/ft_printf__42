CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -I includes -I Libft -g -L Libft -lft
AR = ar
ARFLAGS = rcs

MAKE = make

RM = rm -rf

NAME = libftprintf.a
LIB = libft.a
LIB_DIR = Libft/

BUILD_DIR = build/

SRC_DIR = srcs/
SRCS  = $(addprefix $(SRC_DIR), \
	ft_printf.c \
	utils.c \
	entities/text_raw.c \
	entities/format.c \
	transformers/transformers.c \
	transformers/c_transformers.c \
	transformers/int_transformers.c \
	transformers/unsigned_int_transformers.c \
	transformers/percent_transformer.c \
	transformers/pchar_transformer.c \
	transformers/pvoid_transformer.c \
	transformers/width_transformer.c \
	transformers/sharp_transformer.c \
	transformers/sign_transformer.c \
	transformers/precision_transformer.c \
	parsers/parsers.c \
	parsers/flags/flag_parsers.c \
	parsers/flags/hash_parser.c \
	parsers/flags/minus_parser.c \
	parsers/flags/plus_parser.c \
	parsers/flags/space_parser.c \
	parsers/flags/zero_parser.c \
	parsers/width_parser.c \
	parsers/precision_parser.c \
	parsers/types/int_parsers.c \
	parsers/types/pchar_parsers.c \
	parsers/types/percent_parser.c \
	parsers/types/pvoid_parsers.c \
	parsers/types/types_parsers.c \
	parsers/types/unsigned_int_parsers.c \
	printers.c \
)

OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

# $(NAME): $(BUILD_DIR) $(LIB) $(OBJS)
$(NAME): $(BUILD_DIR) $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo
	@echo "[$(NAME)] Archive generated ✅"

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[$(NAME)] Compiling $<"

$(BUILD_DIR):
	@echo "\n"
	@mkdir -p $(BUILD_DIR)
	@echo "[$(NAME)] Creating build directory"

# $(LIB):
# 	@$(MAKE) -C $(LIB_DIR)

bonus: all
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "[$(NAME)] Bonus successfully added to the archive 🎆"

clean:
	@$(RM) $(BUILD_DIR)
	@$(MAKE) clean -C $(LIB_DIR)
	@echo "[$(NAME)] Cleaning object files 🧼"

fclean: clean
	@$(RM) $(BUILD_DIR) $(NAME)
	@echo "[$(NAME)] Cleaning archive 🧼"

re: fclean all
	@echo "[$(NAME)] Rebuilding all"

rebonus: fclean bonus

test:
	@if [ ! -d "printfTester" ]; then \
		git clone git@github.com:Tripouille/printfTester.git; \
	fi;
	@$(MAKE) -C printfTester

test_bonus:
	@if [ ! -d "printfTester" ]; then \
		git clone git@github.com:Tripouille/printfTester.git; \
	fi;
	@$(MAKE) b -C printfTester

main: all
	$(CC) $(NAME) $(CFLAGS) -o main

.PHONY: all clean fclean re

-include $(DEPS)
