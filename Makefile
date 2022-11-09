#!/bin/bash

objects = stack.a main.o stack.o executable
CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g

all : $(objects)

executable : stack.a main.o
	@$(CC) $(CFLAGS) -lm  -o executable main.o -L. stack.a

stack.a : stack.h stack.o
	@ar -r stack.a stack.o

main.o : main.c stack.o stack.h
	@$(CC) $(CFLAGS) -c main.c

stack.o : stack.h
	@$(CC) $(CFLAGS) -c stack.c

.PHONY : cl
cl :
	rm *.o executable stack.a


