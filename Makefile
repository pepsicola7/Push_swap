NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Werror -Wextra

RM = rm -rf
LIBFTPATH = ./libft/
INSTRUCTION_DIR = Instruction
PARSING_DIR = Parsing
TRIER_DIR = Trier

SRCS =	push_swap.c \
		$(PARSING_DIR)/check_error.c \
		$(PARSING_DIR)/fill_stack.c \
		$(INSTRUCTION_DIR)/ft_swap.c\
		$(INSTRUCTION_DIR)/ft_push.c\
		$(INSTRUCTION_DIR)/ft_rotate.c\
		$(INSTRUCTION_DIR)/ft_reverse_rotate.c\
		$(TRIER_DIR)/Tiny_trier.c\
		$(TRIER_DIR)/multitrier.c\
		$(TRIER_DIR)/optimisation.c\
		$(TRIER_DIR)/cheapest_back.c\
		$(TRIER_DIR)/cheapest_go.c\
		$(TRIER_DIR)/utile.c\
		$(TRIER_DIR)/free.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
LIBFT_FLAGS = -L$(LIBFTPATH) -lft
BONUS_DIR = Bonus

SRCS_BONUS =	$(PARSING_DIR)/check_error.c \
		$(PARSING_DIR)/fill_stack.c \
		$(INSTRUCTION_DIR)/ft_swap.c\
		$(INSTRUCTION_DIR)/ft_push.c\
		$(INSTRUCTION_DIR)/ft_rotate.c\
		$(INSTRUCTION_DIR)/ft_reverse_rotate.c\
		$(TRIER_DIR)/free.c\
		$(BONUS_DIR)/get_next_line_utils.c\
		$(BONUS_DIR)/gnl.c\
		$(BONUS_DIR)/main.c\
		$(BONUS_DIR)/util_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

.c.o:
	cc $(FLAGS) -c -o $@ $<

$(NAME_BONUS):	$(LIBFT) $(OBJS_BONUS)
				$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT_FLAGS)


all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C libft fclean

re: fclean all

.PHONY: all bonus re fclean clean
