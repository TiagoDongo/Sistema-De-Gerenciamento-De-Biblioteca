main: main.o library_functions.o
	gcc -o main main.o library_functions.o

main.o: main.c library_functions.h
	gcc -g -c main.c

library_functions.o: library_functions.c library_functions.h
	gcc -g -c library_functions.c

clean:
	rm -f *.o main