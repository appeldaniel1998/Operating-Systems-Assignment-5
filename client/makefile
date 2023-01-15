CC=clang++
CFLAGS=-c -Wall

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(wildcard *.h)

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o client

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o client

run: main
	./main
