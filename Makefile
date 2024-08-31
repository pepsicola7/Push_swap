NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf
LIBFTPATH = ./libft/
INSTRUCTION_DIR = Instruction
PARSING_DIR = Parsing

SRCS =	push_swap.c \
		$(PARSING_DIR)/check_error.c \
		$(PARSING_DIR)/fill_stack.c \
		print_stack.c \
		$(INSTRUCTION_DIR)/ft_swap.c\
		$(INSTRUCTION_DIR)/ft_push.c\
		$(INSTRUCTION_DIR)/ft_rotate.c\
		$(INSTRUCTION_DIR)/ft_reverse_rotate.c\
		utile.c\
		Tiny_trier.c\
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
