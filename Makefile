NAME = lem-in

SRCS := src/ants.c \
		src/collisions.c \
		src/frees.c \
		src/functions.c \
		src/lem_in.c \
		src/links.c \
		src/main.c \
		src/map.c \
		src/paths.c \
		src/queue.c \
		src/rooms.c \
		src/validation.c \
		src/validation_add.c \
		src/bonus.c

OBJ = $(SRCS:.c=.o)

LIB_DIR = ./libft/
LIBFT = $(LIB_DIR)libftprintf.a
LIB_HDR = $(LIB_DIR)libft.h
FLAGS = -g -Wall -Werror -Wextra
INCLUDE = ./inc/lemin.h

all: $(NAME)

%.o: %.c $(INCLUDE)
	gcc $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L$(LIB_DIR) -I$(LIB_HDR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all