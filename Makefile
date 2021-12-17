CC=gcc
AR=ar
FLAGS= -Wall -g

all: stringProg

stringProg: main.o libtxtFind.a
	$(CC) $(FLAGS) -o stringProg main.o libtxtFind.a
libtxtFind.a: txtFind.o
	$(AR) -rcs libtxtFind.a txtFind.o
main.o: main.c txtFind.h
	$(CC) $(FLAGS) -c main.c
txtFind.o: txtFind.c txtFind.h
	$(CC) $(FLAGS) -c txtFind.c



.PHONY: clean all
clean:
	rm -f *.o *.a *.so stringProg