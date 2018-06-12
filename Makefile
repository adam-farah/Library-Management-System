OBJ = main.o LibControl.o View.o Book.o Patron.o Library.o BookArray.o

lms:	$(OBJ)
	g++ -o lms $(OBJ)

main.o:	main.cc types.h
	g++ -c main.cc

LibControl.o:	LibControl.cc LibControl.h types.h
	g++ -c LibControl.cc

View.o:	View.cc View.h types.h
	g++ -c View.cc

Book.o:	Book.cc Book.h types.h
	g++ -c Book.cc

Patron.o:	Patron.cc Patron.h types.h
	g++ -c Patron.cc

Library.o:	Library.cc Library.h types.h
	g++ -c Library.cc

BookArray.o:	BookArray.cc BookArray.h types.h
	g++ -c BookArray.cc

clean:
	rm -f lms *.o
