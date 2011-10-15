# Makefile

CPP = g++
CFLAGS = -Wall -g
LDFLAGS = -lglut -lGLU -lGL -lX11
OBJS = main.o shapes.o viewing.o
INCLUDE = shapes.h viewing.h

# Compile the program.

all: t02m02

t02m02: $(OBJS)
	$(CPP) $(CFLAGS) -o t02m02 $(OBJS) $(LDFLAGS)

main.o: main.cpp $(INCLUDE)
	$(CPP) $(CFLAGS) -c main.cpp

shapes.o: shapes.cpp $(INCLUDE)
	$(CPP) $(CFLAGS) -c shapes.cpp

viewing.o: viewing.cpp $(INCLUDE)
	$(CPP) $(CFLAGS) -c viewing.cpp
	
clean:
	rm -f t02m02 $(OBJS)