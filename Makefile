#/***           Makefile                ***/
SHELL := /bin/bash 
CURRENT_DIR = $(shell pwd)
PROJECT_NAME = main

all: main clear

main: main.o linked-list.o hash_table.o utilities.o utilities.o
	g++ main.o linked-list.o hash_table.o utilities.o -o main

main.o: main.cpp hash_table.cpp linked-list.cpp utilities.cpp hash_table.h linked-list.h utilities.h
	g++ -c ${PROJECT_NAME}.cpp linked-list.cpp hash_table.cpp utilities.cpp

clear:
	rm *.o