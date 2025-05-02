CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

AR = ar
ARFLAGS = rcs

RM = rm -f

NAME = libftprintf.a

BUILD_DIR = build/

SRCS_DIR = srcs/
# SRCS = (addprefix $(SRCS_DIR), ft_printf.c)
SRCS  = ft_printf.c \

OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Creating $@ archive"

$(BUILD_DIR)%.o: $(BUILD_DIR) $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	@echo "Creating build directory"

bonus: $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Creating $@ bonus archive"

clean:
	$(RM) $(OBJS) $(DEPS)
	@echo "Cleaning object files"

fclean: clean
	$(RM) $(NAME)
	@echo "Cleaning archive"

re: fclean all
	@echo "Rebuilding all"

test:
	~/francinette/tester.sh -m && ~/francinette/tester.sh -ms

test_bonus:
	~/francinette/tester.sh -b && ~/francinette/tester.sh -bs

.PHONY: all clean fclean re

-include $(DEPS)
