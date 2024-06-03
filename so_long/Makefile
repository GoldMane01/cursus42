NAME    := so_long
CFLAGS  := #-Wextra -Wall -Werror -Wunreachable-code
MLX_DIR = ./MLX42
MLX     := $(MLX_DIR)/libmlx42.a
HEADERS := -I$(MLX)
MLX_FLAGS   := -ldl -pthread -lm
SRCS    := so_long.c \
        gnl/get_next_line.c \
        gnl/get_next_line_utils.c \
		lib/ft_strchr.c \
		lib/ft_strlen.c \
		lib/ft_strncmp.c \
		lib/ft_calloc.c

OBJS    := ${SRCS:.c=.o}
all: $(NAME)
libmlx:
	@make -C $(MLX_DIR)
%.o: %.c
	@$(CC) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
$(NAME): $(OBJS) libmlx
	@$(CC) $(OBJS) $(MLX) $(HEADERS) -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME)
clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)
re: clean all
.PHONY: all, clean, fclean, re, libmlx