#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
NAMEBONUS	:= checker
CC        := gcc
FLAGS    := #-Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      lib/ft_atoi.c \
                          lib/ft_lstadd_back.c \
                          lib/ft_lstadd_front.c \
                          lib/ft_lstlast.c \
                          lib/ft_lstnew.c \
                          lib/ft_lstsize.c \
                          lib/ft_split.c \
                          lib/ft_strjoin.c \
                          lib/ft_strlcat.c \
                          lib/ft_strlcpy.c \
                          lib/ft_strlen.c \
                          lib/ft_strncmp.c \
                          lib/ft_substr.c \
                          ops/doubles.c \
                          ops/swaps.c \
                          push_swap.c \
                          utils/errors.c \
                          utils/parse.c \
                          utils/position.c \
                          utils/sort.c \
                          utils/utils.c \

SRCBONUS	:=		bonus/checker_bonus.c \
						  bonus/lib/ft_atoi_bonus.c \
                          bonus/lib/ft_lstadd_back_bonus.c \
                          bonus/lib/ft_lstadd_front_bonus.c \
                          bonus/lib/ft_lstlast_bonus.c \
                          bonus/lib/ft_lstnew_bonus.c \
                          bonus/lib/ft_lstsize_bonus.c \
                          bonus/lib/ft_split_bonus.c \
                          bonus/lib/ft_strjoin_bonus.c \
                          bonus/lib/ft_strlcat_bonus.c \
                          bonus/lib/ft_strlcpy_bonus.c \
                          bonus/lib/ft_strlen_bonus.c \
                          bonus/lib/ft_strncmp_bonus.c \
                          bonus/lib/ft_substr_bonus.c \
						  bonus/lib/ft_strtrim_bonus.c \
						  bonus/lib/ft_strdup_bonus.c \
						  bonus/lib/ft_strchr_bonus.c \
                          bonus/utils/swaps_bonus.c \
                          bonus/utils/errors_bonus.c \
                          bonus/utils/position_bonus.c \
                          bonus/utils/utils_bonus.c \
						  bonus/gnl/get_next_line_bonus.c \
						  bonus/gnl/get_next_line_utils_bonus.c \

OBJS        := $(SRCS:.c=.o)
OBJSBONUS	:= $(SRCBONUS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

${NAMEBONUS}:	${OBJSBONUS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAMEBONUS) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAMEBONUS} ${OBJSBONUS}
			@echo "$(GREEN)$(NAMEBONUS) created[0m ✔️"	

all:		${NAME}

bonus:	${NAMEBONUS}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(NAMEBONUS) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME} ${NAMEBONUS}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(NAMEBONUS) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


