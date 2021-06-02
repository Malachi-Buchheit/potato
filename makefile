CC = g++
CFLAGS = -g -Wall -std=c++11 $(pkg-config --libs glfw3) -lglfw -lGL -lm -lX11 -lpthread -ldl -lGLU -lGLEW -DGLEW_STATIC #-lXrandr -lXi
INCLUDES = -I ./include
SRCS := $(wildcard *.cpp ./src/*/*.cpp)
MAIN = Main

OBJS = $(SRCS:.cpp=.o)

all: $(MAIN) clean run

test: $(MAIN) clean
	valgrind --tool=cachegrind ./$(MAIN)

$(MAIN): $(OBJS)
	@echo Linking...
#	env PKG_CONFIG_PATH=./glfw/src $(CC) $(pkg-config --cflags glfw3) $(CFLAGS) $(pkg-config --libs glfw3) $(INCLUDES) -o $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

.cpp.o:
	@echo Compiling...
#	env PKG_CONFIG_PATH=./glfw/src $(CC) $(pkg-config --cflags glfw3) $(CFLAGS) $(pkg-config --libs glfw3) $(INCLUDES) -c $< -o $@
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@



run:
	./$(MAIN)

clean:
	rm $(OBJS)

depend: $(SRCS)
	makedepend $(INCLUDES) $^




