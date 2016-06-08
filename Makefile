all: datatypes
	cd chapter_01; make
	cd chapter_02; make
	cd chapter_03; make
	cd foolib; make

datatypes: datatypes.c
	gcc datatypes.c -Wall -g -o datatypes

run:
	./datatypes

clean:
	cd chapter_01; make clean
	cd chapter_02; make clean
	cd chapter_03; make clean
	cd foolib; make clean
	rm datatypes
