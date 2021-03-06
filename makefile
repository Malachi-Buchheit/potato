MAIN = run_program
OUT = ./out
VALG = valgrind_output.txt
CAG = cachegrind_output.txt
INCLUDES = -I ./include
SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(OUT)/%.o)

CXX = g++
CXXFLAGS = -g -Wall -std=c++11 $(pkg-config --libs glfw3) -lglfw -lGL -lm -lX11 -lpthread -ldl -lGLU -lGLEW -DGLEW_STATIC #-lXrandr -lXi

.PHONY: all
all: $(MAIN) run

.PHONY: valg
valg: $(MAIN)
	valgrind --log-file="$(OUT)/$(VALG)" --cachegrind-out-file="$(OUT)/$(CAG)" --tool=cachegrind --memtest:leak-check=yes $(OUT)/$(MAIN)
	cg_annotate $(OUT)/$(CAG) > $(OUT)/formatted_cachegrind_output.txt

.PHONY: run
run:
	$(OUT)/$(MAIN)

.PHONY: clean
clean:
	rm -r $(OUT)

.PHONY: push
push:
	git add .
	git commit
	git push

$(MAIN): $(OBJS)
	@echo Linking...
	$(CXX) $(CXXFLAGS) -o $(OUT)/$(MAIN) $(OBJS)
	
$(OUT)/%.cpp.o: %.cpp
	@echo Compiling...
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
