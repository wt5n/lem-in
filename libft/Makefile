NAME = libftprintf.a

SRC = add_func.c \
       adv_itoa.c \
       ap_arith.c \
       ft_printf.c \
       handling_f.c \
       handling_lf.c \
       parsing.c \
       type_b.c \
       type_c.c \
       type_di.c \
       type_di_add.c \
       type_f.c \
       type_f_add.c \
       type_o.c \
       type_other.c \
       type_p.c \
       type_s.c \
       type_u.c \
       type_x.c \
       nulz.c

OBJ = $(SRC:%.c=%.o)

HDR = printf.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror
LIBFTO = ./libft/*.o

all: $(NAME)

$(NAME): $(OBJ1) $(SRC1) $(LIBFT) $(HDR)
	make -C $(LIBFT)
	ar rc $(NAME) $(OBJ1) $(LIBFTO)

%.o:%.c
	gcc -c -Wall -Wextra -Werror -I$(HDR) $<

clean:
	rm -rf $(OBJ1)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re