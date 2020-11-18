NAME = libftprintf.a

SRC1 = printf/add_func.c \
       printf/adv_itoa.c \
       printf/ap_arith.c \
       printf/ft_printf.c \
       printf/handling_f.c \
       printf/handling_lf.c \
       printf/nulz.c \
       printf/parsing.c \
       printf/type_b.c \
       printf/type_c.c \
       printf/type_di.c \
       printf/type_di_add.c \
       printf/type_f.c \
       printf/type_f_add.c \
       printf/type_o.c \
       printf/type_other.c \
       printf/type_p.c \
       printf/type_s.c \
       printf/type_u.c \
       printf/type_x.c

OBJ1 = add_func.o \
       adv_itoa.o \
       ap_arith.o \
       ft_printf.o \
       handling_f.o \
       handling_lf.o \
       nulz.o \
       parsing.o \
       type_b.o \
       type_c.o \
       type_di.o \
       type_di_add.o \
       type_f.o \
       type_f_add.o \
       type_o.o \
       type_other.o \
       type_p.o \
       type_s.o \
       type_u.o \
       type_x.o

HDR = ./inc/
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