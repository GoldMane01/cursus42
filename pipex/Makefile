#--Vars--#

MAGENTA	= \033[0;35m
YELLOW	= \033[0;33m
GREEN	= \033[0;32m
NC		= \033[0m

CC		= gcc
LIBC	= ar -rcs
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

#--Files--#

NAME	= pipex
SRCS	= pipex.c lib.c strings.c command.c cmd.c

OBJS	= $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -I ./ -o $@

$(NAME): $(OBJS)
	@printf "	$(MAGENTA)Compiling \t\t$(GREEN)✓ $(YELLOW)$(NAME)$(NC)\n"
	@$(LIBC) $(NAME) $(OBJS)

#--Commands--#

all: $(NAME)

clean:
	@printf "	$(MAGENTA)Cleaning \t\t$(GREEN)✓ $(YELLOW)Cleaned$(NC)\n"
	@$(RM) $(OBJS)

fclean: clean
	@printf "	$(MAGENTA)Deleting \t\t$(GREEN)✓ $(YELLOW)$(NAME)$(NC)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: .c.o all clean fclean re