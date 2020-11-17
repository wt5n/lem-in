NAME = lem-in

LIBFT = libft.a

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

OBJ = $(SRC:%.c=%.o)

SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/

SRC_PATH = $(SRC:%=$(SRC_DIR)%)
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

all:

clean:

fclean: clean

re: fclean all

.PHONY:			all clean fclean re