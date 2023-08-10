

BUILD_DIR = build

# Targets
all: build

.PHONY: build
build:
	cmake -Bbuild           #to configure cmake
	cmake --build build/ 	#to build all the projects
 
.PHONY:perspective
perspective: build
	./$(BUILD_DIR)/perspective




clean:
	cd build && rm -rf *

