NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_FLAGS = -L./libft -lft
SRCS =	push_swap.c\
		check_erreur.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

$(LIBFT):
	make -C libft

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all