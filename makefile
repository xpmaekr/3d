CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
CXXFLAGS += $(shell pkg-config --cflags raylib)
LDLIBS += $(shell pkg-config --libs raylib)

TARGETS = game editor
COMMON_OBJS = dependences.o

all: $(TARGETS)

game: game.o $(COMMON_OBJS)
	$(CXX) $^ -o $@ $(LDLIBS)

editor: editor.o $(COMMON_OBJS)
	$(CXX) $^ -o $@ $(LDLIBS)

%.o: %.cpp dependences.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run-game: game
	./game

run-editor: editor
	./editor

clean:
	rm -f $(TARGETS) $(COMMON_OBJS) game.o editor.o

.PHONY: all clean run-game run-editor
