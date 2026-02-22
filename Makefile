NAME	=	libftprintf.a
CC		=	cc
CFLAGS	=	-I. -g -Wall -Werror -Wextra

AR		=	ar rcs
RM		=	rm -f

SRC 	=	ft_printf.c ft_printf_utils.c

OBJ		=	$(SRC:.c=.o)

LIBFT_DIR = ft_libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re