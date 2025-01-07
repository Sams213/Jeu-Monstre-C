main: sae.o test.o
	gcc -o main *.o

sae.o: sae.c sae.h
	gcc -c sae.c

test.o: main.c
	gcc -c main.c

clean:
	rm -f *.o main main.exe