CC=gcc
objets= polynome.o queue_pol.o  main.o test.o

all : $(objets)
	$(CC) -o $@ $^

%.o : %.c
	gcc -c -Wall $<

clean : 
	rm -f all *.o
