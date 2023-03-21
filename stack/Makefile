CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g

all: main

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c -o main.o

main: stack.o main.o
	$(CC) $(CFLAGS) stack.o main.o -o main

run: main
	./main

.PHONY: clean

clean:
	rm -f *.o main
