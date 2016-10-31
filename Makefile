#vars

CC=g++
CC_FLAGS=-W -Wall -ansi -std=c++11
LINK_FLAGS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

#files
EXEC=main
SOURCES=$(wildcard *.cpp */*.cpp */*/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

#functions

default: all clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LINK_FLAGS)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

Entity/%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

Manager/%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

Screen/%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

Tool/%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

World/%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@



clean:
	rm -rf *.o */*.o 
