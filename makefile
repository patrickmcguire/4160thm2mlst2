# Makefile

CPP = g++
CFLAGS = -Wall -g
LDFLAGS = -lglut -lGLU -lGL -lX11
OBJS = main.o shapes.o viewing.o menu.o
INCLUDE = shapes.h viewing.h menu.h

# Compile the program.

all: t03m01

t03m01: $(OBJS)
	$(CPP) $(CFLAGS) -o t03m01 $(OBJS) $(LDFLAGS)

main.o: main.cpp $(INCLUDE)
	$(CPP) $(CFLAGS) -c main.cpp

shapes.o: shapes.cpp $(INCLUDE)
	$(CPP) $(CFLAGS) -c shapes.cpp

viewing.o: viewing.cpp $(INCLUDE)
	$(CPP) $(CFLAGS) -c viewing.cpp
	
menu.o: menu.cpp $(INCLUDE)
	$(CPP) $(CFLAGS) -c menu.cpp
	
clean:
	rm -f t03m01 $(OBJS)