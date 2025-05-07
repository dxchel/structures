# Makefile for g++ program for structures
#Made by David Xchel

#VARIABLES
CC = g++
OBJECTS = obj/main.o obj/structures.o obj/test_structures.o

debug: CFLAGS = -g -Wall -Wextra
debug: obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o structures.exe

release: CFLAGS = -O3
release: clear obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o structures.exe
	make clean

obj:
	mkdir obj

${OBJECTS}: obj/%.o: src/%.cpp $(wildcard src/headers/%.hpp)
	${CC} ${CFLAGS} ${CLIBS} -c $< -o $@

clear: clean
	touch structures.exe
	rm -r structures.exe
clean:
	touch obj
	rm -r obj
