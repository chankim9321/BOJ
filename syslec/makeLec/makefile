TARGET = app.out #output
CC = gcc #compiler
M1 = arch -x86_64

app.out : main.o libmine.a
	$(CC) -o app.out -L. main.o -lmine
	
main.o : main.c 
	$(CC) -c main.c

libmine.a : getAvr.o getGrade.o
	 ar ruv libmine.a getAvr.o getGrade.o

getAvr.o : getAvr.c
	$(CC) -c getAvr.c

getGrade.o : getGrade.c
	$(CC) -c getGrade.c


clean:
	rm -f *.o *.a $(TARGET)
	
