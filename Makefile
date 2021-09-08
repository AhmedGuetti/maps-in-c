#/***           Makefile                ***/

PROJECT_NAME = main

all: main clear

main: main.o hash_map.o 
	gcc main.o hash_map.o -o main

main.o: main.c hash_map.c hash_map.h
	gcc -c ${PROJECT_NAME}.c hash_map.c

clear:
	rm *.o