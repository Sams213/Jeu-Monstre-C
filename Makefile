main: sae.o test.o
    gcc -o exec *.o

sae.o: sae.c sae.h
    gcc -c sae.c

main.o: main.c
    gcc -c main.c

clean:
    rm -f *.o sae