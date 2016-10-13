CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lncurses
SOURCES=main.cpp CursesWindow.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ATG

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
