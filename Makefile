CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lSDL2
TARGET = sdl_basic_program
SRC = main.c debug.c timing.c sdl_utils.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
