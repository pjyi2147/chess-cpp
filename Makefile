CXX=g++ 
CXXFLAGS=-std=c++14 -Wall -O -g -MMD -Werror=vla -fsanitize=address

OBJ_DIR=build

SRC_FILES = $(wildcard ./*.cc)
SRC_FILES += $(wildcard Board/*.cc)
SRC_FILES += $(wildcard Piece/*.cc)
SRC_FILES += $(wildcard Player/*.cc)
SRC_FILES += $(wildcard UI/*.cc)
OBJ_FILES = ${patsubst %.cc, $(OBJ_DIR)/%.o, $(SRC_FILES)}

INC_DIRS = include/ncurses

#LIB_DIRS = 
#LIB = 

EXEC=chess

.PHONY: all clean

all: $(OBJ_DIR)/$(EXEC)

clean:
	rm -fr build

$(OBJ_DIR)/$(EXEC): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(OBJ_DIR)/$(EXEC) -I $(INC_DIRS)

build/%.o: %.cc
	mkdir -p $(shell dirname $@)
	$(CXX) -c -o $@ $< $(CXXFLAGS) -I $(INC_DIRS)

-include $(OBJ_FILES:.o=.d)
