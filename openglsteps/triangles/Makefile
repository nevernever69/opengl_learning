

BUILD_DIR = build

# Targets
all: build

.PHONY: build
build:
	cmake -Bbuild           #to configure cmake
	cmake --build build/ 	#to build all the projects
 
.PHONY:triangle1
triangle1: build
	./$(BUILD_DIR)/triangle1

.PHONY:triangle2 
triangle2: build
	./$(BUILD_DIR)/triangle2

.PHONY:square 
square: build
	./$(BUILD_DIR)/square

clean:
	cd build && rm -rf *

