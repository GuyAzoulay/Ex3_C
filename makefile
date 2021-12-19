CC = gcc
FLAGS = -Wall -g

all: stringProg
stringProg: main.c stringProg.c Ex3_C.h
	$(CC) $(FLAGS) main.c stringProg.c Ex3_C.h -o stringProg
.PHONY: clean all

clean:
	rm -f stringProg