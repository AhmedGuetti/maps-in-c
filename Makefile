#/***           Makefile                ***/
SHELL := /bin/bash 
CURRENT_DIR = $(shell pwd)
PROJECT_NAME = main

all: main clear

main: main.o linked-list.o hash_map.o utilities.o utilities.o
	g++ main.o linked-list.o hash_map.o utilities.o -o main

main.o: main.cpp hash_map.cpp linked-list.cpp utilities.cpp hash_map.h linked-list.h utilities.h
	g++ -c ${PROJECT_NAME}.cpp linked-list.cpp hash_map.cpp utilities.cpp

clear:
	rm *.o