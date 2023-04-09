NAME = so_long
LIBFT = libft.a
LIBFT_PATH = ./libft
LIB_FLAGS = -lmlx -lXext -lX11 -lm -lft -L ${LIBFT_PATH}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
APP_SRC = ./app
APP = so_long
SRC_DIR = ./src
OBJ_DIR = ./obj

SRC_FILES = handle_key_events.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all:	${NAME}

${NAME}: ${LIBFT} ${OBJ}
	${CC} ${CFLAGS} ${APP_SRC}/${APP}.c ${OBJ} ${LIB_FLAGS} -o ${APP}

${LIBFT}:
	@echo "Making Libft objects files"
	@make -C ${LIBFT_PATH}
	@echo "Removing libft.o files remaining"
	@make -C ${LIBFT_PATH} clean

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	${CC} ${CFLAGS} ${LIB_FLAGS} -c $< -o $@

clean:
	${RM} ./obj/*.o so_long

.PHONY: all run clean