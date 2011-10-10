all: program

program: Node.o Floor.o
	g++ -o program main.o Floor.o Node.o

main.o: main.cpp
	g++ -c main.cpp

Floor.o: Floor.cpp Node.h Floor.h
	g++ -c Floor.cpp Floor.h Node.h

Node.o: Node.h Node.cpp
	g++ -c Node.cpp Node.h 
	
clean:
	rm main.o Node.o program