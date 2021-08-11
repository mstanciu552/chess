CC = gcc
FLAGS = -Wall -Wextra -lSDL2main -lSDL2 -lSDL2_image -g
OBJ = main.c pieces.h board.h

LINK = /usr/local/include/SDL2

all: build run

build: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o build/main 

run: build/main
	build/main

clean:
	rm build/main

.PHONY: clean

