NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_printf_utils.c \
		ft_ull_to_hex.c \
		ft_putuint_fd.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./ -I./libft/
LIBFT_PATH = ./libft
LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT_PATH)/$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean