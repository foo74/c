# Makefile for Chapter 3 exercises.
# by foo74
all: kenlib ex01 ex02

kenlib: ../kenlib/print.h ../kenlib/print.c
	cd ../kenlib; make

# For some reason the -Wl,-z,stacksize= is ignored. The -Wl flag means
# to send the -z stacksize= flag to the linker. But ld ignores it. why?
ex01: ex_03-01.c 
	gcc ex_03-01.c -Wall -g -c -o ex_03-01.o
	gcc -Wl,-z,stacksize=16600000 -o ex_03-01 ex_03-01.o ../kenlib/print.o

ex02: ex_03-02.c 
	gcc ex_03-02.c -Wall -g -c -o ex_03-02.o
	gcc -o ex_03-02 ex_03-02.o

run:
	./ex_03-02

clean:
	cd ../kenlib; make clean
	rm ex_03-01 ex_03-01.o ex_03-02 ex_03-02.o
