TARGET = app.out

app.out : main.o libmine.a
	gcc -o app.out -L. main.o -lmine
	
main.o : main.c 
	gcc -c main.c

libmine.a : getGrade.o
	ar ruv libmine.a getGrade.o
libmine.a : getAvr.o
	ar ruv libmine.a getAvr.o

getAvr.o : getAvr.c
	gcc -c getAvr.c

getGrade.o : getGrade.c
	gcc -c getGrade.c


clean:
	rm -f *.o
	rm -f $(TARGET)
