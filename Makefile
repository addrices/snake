CC = gcc
CXX = g++
CFLAGS += -lncurses
SRC_DIR = ./
CPP_FILES = $(shell find $(SRC_DIR) -name "*.cpp")
HPP_FILES = $(shell find $(SRC_DIR) -name "*.hpp")
SNAKE = snake

$(SNAKE): $(CPP_FILES) $(HPP_FILES)
	$(CXX) $(CPP_FILES) -o $@ $(CFLAGS)

run: $(SNAKE)
	./$<

debug: $(CPP_FILES) $(HPP_FILES)
	$(CXX) $(CPP_FILES) -o $@ $(CFLAGS) -g

clean:
	rm $(SNAKE) debug