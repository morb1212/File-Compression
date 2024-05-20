.PHONY: clean all test
CC = gcc
FLAGS= -g -Wall

all: compress test

clean:
	rm -f *.o *.a compress test

compress: compress.o encodemain.o
	$(CC) $(FLAGS)  compress.o encodemain.o -o compress

test: test.o compress.o
	$(CC) $(FLAGS) test.o compress.o -o test

compress.o: compress.c compress.h
	$(CC) $(FLAGS) -c compress.c

encodemain.o: encodemain.c compress.h
	$(CC) $(FLAGS) -c encodemain.c

test.o: test.c compress.h
	$(CC) $(FLAGS) -c test.c

compress.a: compress.o 
	ar -rcs compress.a compress.o 
