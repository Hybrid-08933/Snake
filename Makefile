# -*- Makefile -*-

CC = gcc
CFLAGS = -Wall -ggdb3 -O0 --std=c99 -D_REENTRANT
LDFLAGS = -lSDL2

SRC_DIR = ./src/
BIN_DIR = ./bin/

all: main

main: main.o draw.o input.o init.o
	$(CC) -o $(BIN_DIR)main $(BIN_DIR)main.o $(BIN_DIR)draw.o $(BIN_DIR)input.o $(BIN_DIR)init.o $(CFLAGS) $(LDFLAGS)

main.o: $(SRC_DIR)main.c $(SRC_DIR)main.h $(SRC_DIR)structs.h $(SRC_DIR)init.h $(SRC_DIR)draw.h $(SRC_DIR)input.h
	$(CC) -o $(BIN_DIR)main.o -c $(SRC_DIR)main.c $(CFLAGS)

init.o: $(SRC_DIR)init.c $(SRC_DIR)init.h $(SRC_DIR)defs.h $(SRC_DIR)structs.h
	$(CC) -o $(BIN_DIR)init.o -c $(SRC_DIR)init.c $(CFLAGS)

draw.o: $(SRC_DIR)draw.c $(SRC_DIR)draw.h $(SRC_DIR)defs.h $(SRC_DIR)structs.h
	$(CC) -o $(BIN_DIR)draw.o -c $(SRC_DIR)draw.c $(CFLAGS)

input.o: $(SRC_DIR)input.c $(SRC_DIR)input.h
	$(CC) -o $(BIN_DIR)input.o -c $(SRC_DIR)input.c $(CFLAGS)

.PHONY: all clean
clean:
	rm $(BIN_DIR)*
