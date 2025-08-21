INCDIR = ./include

CXX = g++
CXXFLAGS = -std=c++20 -I $(INCDIR) -Wall -g
LDFLAGS = 

SRCDIR = ./src
BUILDDIR = ./build

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

TARGET = main

.PHONY: all build clean run

all: build

run: $(TARGET)
	./$(TARGET)

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ -o $(TARGET) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) $< -c -o $@ $(CXXFLAGS)


clean:
	rm $(OBJS) $(TARGET)