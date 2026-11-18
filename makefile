CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
CXXFLAGS += $(shell pkg-config --cflags raylib)
LDLIBS += $(shell pkg-config --libs raylib)

# Всё собирается в build/ (создаётся автоматически)
BUILD = build

# Бинарники (по одному на файл с main()). Новую программу = добавить имя сюда.
TARGETS = $(addprefix $(BUILD)/,game editor)

# Все остальные .cpp автоматически считаются общим кодом
ENTRY_SRCS = $(addsuffix .cpp,$(notdir $(TARGETS)))
SHARED_SRCS = $(filter-out $(ENTRY_SRCS) main.cpp compile.cpp,$(wildcard *.cpp))
SHARED_OBJS = $(addprefix $(BUILD)/,$(SHARED_SRCS:.cpp=.o))

all: $(TARGETS)

$(BUILD)/%: $(BUILD)/%.o $(SHARED_OBJS) | $(BUILD)
	$(CXX) $^ -o $@ $(LDLIBS)

$(BUILD)/%.o: %.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD):
	mkdir -p $@

run-game: $(BUILD)/game
	./$(BUILD)/game

run-editor: $(BUILD)/editor
	./$(BUILD)/editor

clean:
	rm -rf $(BUILD)

-include $(SHARED_OBJS:.o=.d) $(addsuffix .d,$(basename $(TARGETS)))

.PHONY: all clean run-game run-editor
