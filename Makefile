NAME = push_swap

SRCS = push_swap.c manage_node.c set_index.c sort.c \
       push.c swap.c rotate.c reverse_rotate.c \
       merge.c atol.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a


CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT) $(PRINTF_LIB)
	# リンクのルールにft_printfのライブラリを追加
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)


$(LIBFT):
	make -C $(LIBFT_DIR)


$(PRINTF_LIB):
	make -C $(PRINTF_DIR)


clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	# --- ここから追加 ---
	make -C $(PRINTF_DIR) clean
	# --- 追加ここまで ---

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	# --- ここから追加 ---
	make -C $(PRINTF_DIR) fclean
	# --- 追加ここまで ---

re: fclean all

.PHONY: all clean fclean re
