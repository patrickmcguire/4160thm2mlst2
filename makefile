CFLAGS = -Wall

all: program

program: Node.o Floor.o main.o
	g++ $(CFLAGS) -o program main.o Floor.o Node.o

main.o: main.cpp Node.h Floor.h
	g++ $(CFLAGS) -c main.cpp Node.h Floor.h

Floor.o: Floor.cpp Node.h Floor.h
	g++ $(CFLAGS) -c Floor.cpp Floor.h Node.h

Node.o: Node.h Node.cpp
	g++ $(CFLAGS) -c Node.cpp Node.h 
	
clean:
	rm *.o *.gch program