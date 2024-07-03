DEBUG ?= 1
ENABLE_WARNINGS ?= 1

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build
EXECUTABLE_NAME = main
CXX_SOURCES = $(wildcard $(SOURCE_DIR)/*.cc) 
CXX_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cc, $(BUILD_DIR)/%.o, $(CXX_SOURCES)) 

CXX = g++
CXX_STANDARD = c++17
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)
CPPFLAGS = -I $(INCLUDE_DIR)
LDFLAGS =  -lncurses


ifeq (%(ENABLE_WARNINGS), 1)
CXX_WARNINGS = -Wall -Wextra -Wpedantic
else
CXX_WARNINGS =
endif

ifeq ($(DEBUG), 1)
CXXFLAGS += -g -O0
else
CXXFLAGS += -O3
endif

CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS) $(CPPFLAGS)

# TARGETS

init:
	mkdir $(SOURCE_DIR)
	mkdir $(INCLUDE_DIR)
	touch $(SOURCE_DIR)/main.cc

create: 
	mkdir -p $(BUILD_DIR)

build: clean create $(CXX_OBJECTS)
	$(CXX_COMPILER_CALL) $(CXX_OBJECTS) $(LDFLAGS) -o $(BUILD_DIR)/$(EXECUTABLE_NAME)

execute: 
	$(BUILD_DIR)/$(EXECUTABLE_NAME)

clean: 
	rm -f ./$(BUILD_DIR)/*.o
	rm -f ./$(BUILD_DIR)/$(EXECUTABLE_NAME)

# PATTERNS
# $@ - file name of target
# $< - name of first dependency
# $^ - name of all prerequisites

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cc
	$(CXX_COMPILER_CALL) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX_COMPILER_CALL) -c $< -o $@

.PHONY: init build execute clean