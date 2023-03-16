TARGET = myapp.out
CC = gcc

myapp.out : main.o libmine.a
	$(CC) -o app.out -L. main.o -lmine

fibo.o : main.c
	$(CC) -c main.c

libmine.a : myfibo.o
	ar ruv libmine.a myfibo.o

myfibo.o : myfibo.c
	$(CC) -c myfibo.c

clean:
	rm -f *.o
	rm -f $(TARGET);

