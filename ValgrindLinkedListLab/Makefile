#############################################################################
# File name:  Makefile
# Author:     Computer Science, Pacific University
# Date:       9.28.16
# Class:      CS 300
# Assignment: In Class Dynamic Memory Lab
# Purpose: 	  This is the Makefile for the In Class Dynamic Memory Lab    
#############################################################################

CC=gcc

# the -w command disables all warnings
# You should never use this.  It is used here merely as an exercise.
CFLAGS=-g -w

.PHONY: all clean

TARGETS= bin bin/mainList bin/mainArrays

all: ${TARGETS}

bin:
	mkdir -p bin
	
bin/mainList: bin/mainList.o
	${CC} ${CFLAGS} -o bin/mainList bin/mainList.o

bin/mainList.o: src/mainList.c
	${CC} ${CFLAGS} -c -o bin/mainList.o src/mainList.c
	
bin/mainArrays: bin/mainArrays.o
	${CC} ${CFLAGS} -o bin/mainArrays bin/mainArrays.o

bin/mainArrays.o: src/mainArrays.c
	${CC} ${CFLAGS} -c -o bin/mainArrays.o src/mainArrays.c

clean:
	rm -rf bin/*.o ${TARGETS}
	
valgrindList:
	valgrind -v --leak-check=yes bin/mainList

valgrindArrays:
	valgrind -v --leak-check=yes bin/mainArrays


# NOTE:
# $$USER will contain your login name
# the value in $$USER can be seen at the command line by typing
# echo $USER

tarball: clean
	cd ..; tar czf ~/ValgrindLinkedListLab_$$USER.tar.gz ValgrindLinkedListLab