CC = gcc
FLAGS = -Wall -g

all: stringProg
stringProg: main.c stringProg.c stringProg.h
	$(CC) $(FLAGS) main.c stringProg.c stringProg.h -o stringProg
.PHONY: clean all

clean:
	rm -f stringProg