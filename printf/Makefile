# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 15:45:02 by ksenaida          #+#    #+#              #
#    Updated: 2020/11/18 13:57:53 by wtsn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC1 = src/add_func.c \
       src/adv_itoa.c \
       src/ap_arith.c \
       src/ft_printf.c \
       src/handling_f.c \
       src/handling_lf.c \
       src/nulz.c \
       src/parsing.c \
       src/type_b.c \
       src/type_c.c \
       src/type_di.c \
       src/type_di_add.c \
       src/type_f.c \
       src/type_f_add.c \
       src/type_o.c \
       src/type_other.c \
       src/type_p.c \
       src/type_s.c \
       src/type_u.c \
       src/type_x.c

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

HDR = ./includes/
LIBFT = ./src/libft/
FLAGS = -Wall -Wextra -Werror
LIBFTO = ./src/libft/*.o

all: $(NAME)

$(NAME):
		@make -C $(LIBFT)
		@gcc $(FLAGS) -c $(SRC1) -I $(HDR)
		@ar rc $(NAME) $(OBJ1) $(LIBFTO)

clean:
	rm -rf $(OBJ1)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
