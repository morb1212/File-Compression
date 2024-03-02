.PHONY: clean all
CC = gcc
FLAGS= -g -Wall

all: compress

clean:
	rm -f *.o *.a compress

compress: compress.o encodemain.o
	$(CC) $(FLAGS)  compress.o encodemain.o -o compress
compress.o: compress.c compress.h
	$(CC) $(FLAGS) -fPIC -c compress.c
encodemain.o: encodemain.c compress.h
	$(CC) $(FLAGS) -c encodemain.c
compress.a: compress.o 
	ar -rcs compress.a compress.o 

