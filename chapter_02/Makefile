all: kenlib ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8

kenlib: ../kenlib/print.h ../kenlib/print.c
	cd ../kenlib; make

ex1: ex_02-01.c
	gcc ex_02-01.c -Wall -g -o ex_02-01

ex2: ex_02-02.c
	gcc ex_02-02.c -Wall -g -o ex_02-02

ex3: ex_02-03.c
	gcc ex_02-03.c -Wall -g -lm -o ex_02-03

ex4: ex_02-04.c
	gcc ex_02-04.c -Wall -g -o ex_02-04

ex5: ex_02-05.c
	gcc ex_02-05.c -Wall -g -o ex_02-05

ex6: ex_02-06.c
	gcc ex_02-06.c -Wall -g -o ex_02-06

ex7: ex_02-07.c 
	gcc ex_02-07.c -Wall -g -c -o ex_02-07.o
	gcc -o ex_02-07 ex_02-07.o ../kenlib/print.o

ex8: ex_02-08.c 
	gcc ex_02-08.c -Wall -g -c -o ex_02-08.o
	gcc -o ex_02-08 ex_02-08.o ../kenlib/print.o

run:
	./ex_02-08

clean:
	cd ../kenlib; make clean
	rm ex_02-01 ex_02-02 ex_02-03 ex_02-04 ex_02-05 ex_02-06 ex_02-07 ex_02-07.o ex_02-08 ex_02-08.o
