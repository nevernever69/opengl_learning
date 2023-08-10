

BUILD_DIR = build

# Targets
all: build

.PHONY: build
build:
	cmake -Bbuild           #to configure cmake
	cmake --build build/ 	#to build all the projects
 
.PHONY:rotatetex
rotatetex: build
	./$(BUILD_DIR)/rotatetex

.PHONY:movetex
movetex: build
	./$(BUILD_DIR)/movetex




clean:
	cd build && rm -rf *

