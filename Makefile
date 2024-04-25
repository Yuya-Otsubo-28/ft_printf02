NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_printf_utils.c \
		ft_ull_to_hex.c \
		ft_putuint_fd.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./ -I./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a .
	mv libft.a $(NAME)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	make clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
