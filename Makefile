CC=gcc

all: main.o
	$(CC) main.o -o bin

main.o:
	$(CC) -c main.c -o main.o