all: kenlib ex01

kenlib: ../kenlib/print.h ../kenlib/print.c
	cd ../kenlib; make

ex01: ex_03-01.c 
	gcc ex_03-01.c -Wall -g -c -o ex_03-01.o
	gcc -o ex_03-01 ex_03-01.o ../kenlib/print.o

run:
	./ex_03-01

clean:
	cd ../kenlib; make clean
	rm ex_03-01 ex_03-01.o
