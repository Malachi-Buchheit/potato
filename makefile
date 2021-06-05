MAIN = run_program
INCLUDES = -I ./include
OUT = ./out
VALG = valgrind_output.txt
CAG = cachegrind_output.txt
SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(OUT)/%.o)

CC = g++
CFLAGS = -g -Wall -std=c++11 $(pkg-config --libs glfw3) -lglfw -lGL -lm -lX11 -lpthread -ldl -lGLU -lGLEW -DGLEW_STATIC #-lXrandr -lXi

all: $(MAIN) run

test: $(MAIN)
	valgrind --log-file="$(OUT)/$(VALG)" --cachegrind-out-file="$(OUT)/$(CAG)" --tool=cachegrind --memtest:leak-check=yes $(OUT)/$(MAIN)
	cg_annotate $(OUT)/$(CAG) > $(OUT)/formatted_cachegrind_output.txt

$(MAIN): $(OBJS)
	@echo Linking...
	$(CC) $(CFLAGS) -o $(OUT)/$(MAIN) $(OBJS)
	
$(OUT)/%.cpp.o: %.cpp
	@echo Compiling...
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run:
	$(OUT)/$(MAIN)

clean:
	rm -r $(OUT)
