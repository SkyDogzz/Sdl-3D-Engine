CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lSDL2
TARGET = sdl_basic_program
SRC = main.c debug.c timing.c sdl_utils.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
