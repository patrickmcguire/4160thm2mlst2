all: program

program: main.o Node.o
	g++ main.o Node.o -o program

main.o:
	g++ -c main.cpp

Node.o:
	g++ -c Node.cpp
	
clean:
	rm main.o Node.o program