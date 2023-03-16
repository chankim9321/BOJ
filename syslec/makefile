TARGET = app.out #output
CC = gcc #compiler

app.out : main.o libmine.a
	$(CC) -o app.out -L. main.o -lmine
	
main.o : main.c 
	$(CC) -c main.c

libmine.a : getGrade.o
	ar ruv libmine.a getGrade.o
libmine.a : getAvr.o
	ar ruv libmine.a getAvr.o

getAvr.o : getAvr.c
	$(CC) -c getAvr.c

getGrade.o : getGrade.c
	$(CC) -c getGrade.c


clean:
	rm -f *.o
	rm -f $(TARGET)
