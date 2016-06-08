# Makefile for Chapter 3 exercises.
# by foo74
all: foolib ex01 ex02 ex03

foolib: ../foolib/print.h ../foolib/print.c
	cd ../foolib; make

# For some reason the -Wl,-z,stacksize= is ignored. The -Wl flag means
# to send the -z stacksize= flag to the linker. But ld ignores it. why?
ex01: ex_03-01.c ex_03-01.h
	gcc ex_03-01.c -Wall -g -c -o ex_03-01.o
	gcc -Wl,-z,stacksize=16600000 -o ex_03-01 ex_03-01.o ../foolib/print.o

ex02: ex_03-02.c ex_03-02.h
	gcc ex_03-02.c -Wall -g -c -o ex_03-02.o
	gcc -o ex_03-02 ex_03-02.o

ex03: ex_03-03.c ex_03-03.h
	gcc ex_03-03.c -Wall -g -c -o ex_03-03.o
	gcc -o ex_03-03 ex_03-03.o

run:
	./ex_03-03

clean:
	cd ../foolib; make clean
	rm ex_03-01 ex_03-01.o ex_03-02 ex_03-02.o ex_03-03 ex_03-03.o
