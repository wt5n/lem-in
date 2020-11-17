NAME = libft.a

SRCS = ./*.c

OBJECTS = ./*.o

INCLUDES = ./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	gcc -Wall -Werror -Wextra -I$(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all