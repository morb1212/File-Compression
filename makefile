.PHONY: clean all test
CC = gcc
FLAGS = -g -Wall

all: compress test

clean:
	rm -f *.o *.a compress test inputC.txt inputC.bin inputD.txt inputD.bin

compress: encodemain.o compress.o
	$(CC) $(FLAGS) encodemain.o compress.o -o compress

test: test.o compress.o
	$(CC) $(FLAGS) test.o compress.o -o test

compress.o: compress.c compress.h
	$(CC) $(FLAGS) -c compress.c -o compress.o

encodemain.o: encodemain.c compress.h
	$(CC) $(FLAGS) -c encodemain.c -o encodemain.o

test.o: test.c compress.h
	$(CC) $(FLAGS) -c test.c -o test.o

compress.a: compress.o
	ar -rcs compress.a compress.o
