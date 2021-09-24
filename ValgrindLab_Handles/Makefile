#############################################################################
# File name:  Makefile
# Author:     $Author: chadd $
# Date:       $Date: 2011-10-31 08:27:24 -0700 (Mon, 31 Oct 2011) $
# Class:      CS 300
# Assignment: In Class Dynamic Memory Lab
# Purpose: 		This is the Makefile for the In Class Dynamic Memory Lab    
# RevisionID:  $Id: Makefile 12 2011-10-31 15:27:24Z chadd $ 
#############################################################################

CC=gcc

# the -w command disables all warnings
# You should never use this.  It is used here merely as an exercise.
CFLAGS=-g -w

.PHONY: all clean

TARGETS= bin/dynamicArrays bin/dynamicList

all: bin ${TARGETS}

bin:
	mkdir -p bin
	
bin/dynamicArrays: bin/dynamicArrays.o
	${CC} ${CFLAGS} -o bin/dynamicArrays bin/dynamicArrays.o

bin/dynamicArrays.o: src/dynamicArrays.c
	${CC} ${CFLAGS} -c -o bin/dynamicArrays.o src/dynamicArrays.c

bin/dynamicList: bin/dynamicList.o
	${CC} ${CFLAGS} -o bin/dynamicList bin/dynamicList.o

bin/dynamicList.o: src/dynamicList.c
	${CC} ${CFLAGS} -c -o bin/dynamicList.o src/dynamicList.c

clean:
	rm -rf bin/*.o ${TARGETS}