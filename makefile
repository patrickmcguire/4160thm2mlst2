CFLAGS = -g -O0 -Wall -I/usr/include/GL/ -lGL -lglut -lGLU

all: program

program: Node.o Floor.o main.o Box.o Teapot.o Torus.o Sphere.o
	g++ $(CFLAGS) -o program main.o Floor.o Box.o Teapot.o Torus.o Sphere.o Node.o

main.o: main.cpp Node.h Floor.h
	g++ $(CFLAGS) -c main.cpp

Floor.o: Floor.cpp Node.h Floor.h
	g++ $(CFLAGS) -c Floor.cpp

Node.o: Node.h Node.cpp
	g++ $(CFLAGS) -c Node.cpp
	
Box.o: Box.cpp Node.h Box.h
	g++ $(CFLAGS) -c Box.cpp

Teapot.o: Teapot.cpp Teapot.h Node.h
	g++ $(CFLAGS) -c Teapot.cpp
	
Torus.o: Torus.cpp Torus.h Node.h
	g++ $(CFLAGS) -c Torus.cpp
	
Sphere.o: Sphere.cpp Sphere.h Node.h
	g++ $(CFLAGS) -c Sphere.cpp
	
clean:
	rm *.o *.gch program