NAME = lem-in

SRC = ants.c \
      collisions.c \
      frees.c \
      functions.c \
      lem_in.c \
      links.c \
      main.c \
      map.c \
      paths.c \
      queue.c \
      rooms.c \
      validation.c \
      validation_add.c

OBJSFD 	= tmp

OBJ 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

LIB_BINARY	= -L./libft -lft
SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/
HDR = -I./inc
HDR_FILE = ./inc/lem-in.h
WFLAGS = -Wall -Wextra -Werror

SRC_PATH = $(SRC:%=$(SRC_DIR)%)
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

LIBFT = ./libft/libftprintf.a
LIBFT_HDR = ./libft/printf.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(WFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(HDR)
	gcc -g $(WFLAGS) $(LIB_BINARY) -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJSFD)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf -f $(NAME)

re: fclean all

.PHONY:			all clean fclean re