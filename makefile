CFLAGS = -g -O0 -Wall -I/usr/include/GL/ -lGL -lglut -lGLU

all: program

program: main.o
	g++ $(CFLAGS) -o program main.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp
	
clean:
	rm -f *.o program