INCDIR = ./include

CXX = g++
CXXFLAGS = -std=c++20 -I $(INCDIR) -Wall
LDFLAGS = 

SRCS = ./src/main.cpp ./src/my_module.cpp 
OBJS = $(patsubst ./src/%.cpp,./build/%.o,$(SRCS))
TARGET = main

.PHONY: all build clean run

all: build

run: $(TARGET)
	./$(TARGET)

build: $(OBJS)
	$(CXX) $^ -o $(TARGET) $(LDFLAGS)

./build/%.o: ./src/%.cpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)

clean:
	rm $(OBJS) $(TARGET)