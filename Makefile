list: test.o padre.o
	gcc -o list test.o padre.o
test.o: test.c padre.h
	gcc -c test.c
padre.o: padre.c padre.h
	gcc -c padre.c
run: list
	./list