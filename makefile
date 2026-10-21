CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
CXXFLAGS += $(shell pkg-config --cflags raylib)
LDLIBS += $(shell pkg-config --libs raylib)

TARGET = game

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $@ $(LDLIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
