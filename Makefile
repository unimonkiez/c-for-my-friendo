CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g

all: find_dups

find_dups.o: src/find_dups.c
	$(CC) $(CFLAGS) -c src/find_dups.c -o find_dups.o

find_dups: find_dups.o
	$(CC) $(CFLAGS) find_dups.o -o find_dups

run: clean find_dups
	./find_dups

.PHONY: clean

clean:
	rm -f *.o find_dups