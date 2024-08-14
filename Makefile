NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -g
RM = rm -rf
LIBFTPATH = ./libft/
INSTRUCTION_DIR = Instruction

SRCS =	push_swap.c \
		check_error.c \
		swap.c \
		print_stack.c \
		$(INSTRUCTION_DIR)/ft_swap.c\
		$(INSTRUCTION_DIR)/ft_push.c\
		$(INSTRUCTION_DIR)/ft_rotate.c\
		$(INSTRUCTION_DIR)/ft_reverse_rotate.c\
		trier_trois.c\
		trier_cinq.c\
		multitrier.c

OBJS = $(SRCS:.c=.o)
LIBFTMAKE	= $(MAKE) -C $(LIBFTPATH)
LIBFT		= -L$(LIBFTPATH) -lft

all: $(NAME)


$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

.c.o:
	cc $(FLAGS) -c -o $@ $<


$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


# NAME		= push_swap

# CFLAGS		= -Wall -Wextra -Werror

# SRCS =	push_swap.c\
# 		check_erreur.c\
# 		swap.c

# OBJS		= $(SRCS:.c=.o)

# LIBFTPATH	= ./libft/
# LIBFTMAKE	= $(MAKE) -C $(LIBFTPATH)
# LIBFT		= -L$(LIBFTPATH) -lft

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(LIBFTMAKE)
# 	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# .c.o:
# 	cc $(CFLAGS) -c -o $@ $<

# clean:
# 	$(LIBFTMAKE) clean
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(LIBFTMAKE) fclean
# 	$(RM) $(NAME)

# re: fclean all
