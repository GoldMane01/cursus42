#--Vars--#

MAGENTA	= \033[0;35m
YELLOW	= \033[0;33m
GREEN	= \033[0;32m
NC		= \033[0m

CC		= gcc
LIBC	= ar rcs
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

#--Files--#

NAME	= libft.a
SRCS	= ft_isalpha.c ft_isdigit.c ft_isprint.c \
			ft_isalnum.c ft_isascii.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_tolower.c ft_toupper.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c  ft_strnstr.c ft_atoi.c \
			ft_memmove.c ft_strlcat.c ft_strlcpy.c \
			ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS	= ft_lstnew_bonus.c

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BONUS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -I ./ -o $@

$(NAME): $(OBJS)
	@printf "	$(MAGENTA)Compiling \t\t$(GREEN)✓ $(YELLOW)$(NAME)$(NC)\n"
	@$(LIBC) $(NAME) $(OBJS)

#--Commands--#

all: $(NAME)

bonus: $(BOBJS)
	@printf "	$(MAGENTA)Compiling \t\t$(GREEN)✓ $(YELLOW)$(NAME)$(NC)\n"
	@$(LIBC) $(NAME) $(BOBJS)

clean:
	@printf "	$(MAGENTA)Cleaning \t\t$(GREEN)✓ $(YELLOW)Cleaned$(NC)\n"
	@$(RM) $(OBJS) $(BOBJS)

fclean: clean
	@printf "	$(MAGENTA)Deleting \t\t$(GREEN)✓ $(YELLOW)$(NAME)$(NC)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: .c.o all clean fclean re