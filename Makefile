# -*- Makefile -*-

CC = gcc
CFLAGS = -Wall -ggdb3 -O0 --std=c99 -D_REENTRANT
LDFLAGS = -lSDL2

SRC_DIR = ./src/
BIN_DIR = ./bin/

all: $(BIN_DIR)main

$(BIN_DIR)main: $(BIN_DIR)main.o $(BIN_DIR)draw.o $(BIN_DIR)input.o $(BIN_DIR)init.o $(BIN_DIR)snake.o
	$(CC) -o $(BIN_DIR)main $(BIN_DIR)main.o $(BIN_DIR)draw.o $(BIN_DIR)input.o $(BIN_DIR)init.o $(BIN_DIR)snake.o $(CFLAGS) $(LDFLAGS)

$(BIN_DIR)main.o: $(SRC_DIR)main.c $(SRC_DIR)main.h $(SRC_DIR)structs.h $(SRC_DIR)init.h $(SRC_DIR)draw.h $(SRC_DIR)input.h
	$(CC) -o $(BIN_DIR)main.o -c $(SRC_DIR)main.c $(CFLAGS)

$(BIN_DIR)init.o: $(SRC_DIR)init.c $(SRC_DIR)init.h $(SRC_DIR)defs.h $(SRC_DIR)structs.h $(SRC_DIR)snake.h
	$(CC) -o $(BIN_DIR)init.o -c $(SRC_DIR)init.c $(CFLAGS)

$(BIN_DIR)draw.o: $(SRC_DIR)draw.c $(SRC_DIR)draw.h $(SRC_DIR)defs.h $(SRC_DIR)structs.h
	$(CC) -o $(BIN_DIR)draw.o -c $(SRC_DIR)draw.c $(CFLAGS)

$(BIN_DIR)input.o: $(SRC_DIR)input.c $(SRC_DIR)input.h $(SRC_DIR)structs.h
	$(CC) -o $(BIN_DIR)input.o -c $(SRC_DIR)input.c $(CFLAGS)

$(BIN_DIR)snake.o: $(SRC_DIR)snake.c $(SRC_DIR)snake.h $(SRC_DIR)defs.h $(SRC_DIR)structs.h
	$(CC) -o $(BIN_DIR)snake.o -c $(SRC_DIR)snake.c $(CFLAGS)

.PHONY: all clean
clean:
	rm $(BIN_DIR)*
