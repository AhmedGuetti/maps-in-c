#/***           Makefile                ***/
SHELL = cmd
CURRENT_DIR = cd
PROJECT_NAME = main

all: main clear

main: main.o linked-list.o hash_map.o utilities.o utilities.o
	g++ main.o linked-list.o hash_map.o utilities.o -o main

<<<<<<< HEAD
main.o: main.cpp map.cpp linked-list.cpp utilities.cpp map.h linked-list.h utilities.h
	g++ -c $(PROJECT_NAME).cpp linkedList.cpp map.cpp utilities.cpp
=======
main.o: main.cpp hash_map.cpp linked-list.cpp utilities.cpp hash_map.h linked-list.h utilities.h
	g++ -c ${PROJECT_NAME}.cpp linked-list.cpp hash_map.cpp utilities.cpp
>>>>>>> 0f252618036beb13f0e0be1500080a052ec9f154

clear:
	rm *.o