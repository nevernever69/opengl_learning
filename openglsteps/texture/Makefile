

BUILD_DIR = build

# Targets
all: build

.PHONY: build
build:
	cmake -Bbuild           #to configure cmake
	cmake --build build/ 	#to build all the projects
 
.PHONY:texture1 
texture1: build
	./$(BUILD_DIR)/texture1 

.PHONY:texture2 
texture2: build
	./$(BUILD_DIR)/texture2

clean:
	cd build && rm -rf *

