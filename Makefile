main: main.o library_functions.o user_functions.o
	gcc -o main main.o library_functions.o user_functions.o

main.o: main.c library_functions.h
	gcc -g -c main.c

library_functions.o: library_functions.c library_functions.h
	gcc -g -c library_functions.c

user_functions.o: user_functions.c user_functions.h
	gcc -g -c user_functions.c

clean:
	rm -f *.o main