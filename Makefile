CC = g++
CFLAGS = -Wall -std=c++14 -Iinclude
LDFLAGS =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = timestamp

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(BIN_DIR)/$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@
	@echo "Linking complete"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo "Compiled "$<" successfully!"

.PHONY: init clean run

init:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	@echo "Created Project Structure"

clean:
	rm -f $(OBJ)
	rm -f $(BIN_DIR)/$(TARGET)
	@echo "Objects and executables removed!"

run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET) $(filter-out $@,$(MAKECMDGOALS))

%:
	@:
