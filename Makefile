CC=g++
CC_FLAGS=-g -Wall
CC_LIBS=

SRC_DIR=src
HDR_DIR=include
OBJ_DIR=obj

# source and object files
SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

BIN_FILE=blockchain

all: $(OBJ_DIR) $(BIN_FILE)

$(BIN_FILE): $(OBJ_FILES)
	$(CC) $(CC_FLAGS) $^ -I$(HDR_DIR) -o $@ $(CC_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CC_FLAGS) -c $^ -I$(HDR_DIR) -o $@ $(LFLAGS)

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(BIN_FILE) $(OBJ_DIR)