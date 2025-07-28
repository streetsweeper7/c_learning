# Compiler settings
CC := gcc
CFLAGS := -Wall -Wextra -O2

# Directories
SRC_DIR := ./source
INC_DIR := ./include
OBJ_DIR := ./build

# Files
SRC_FILES := $(shell find $(SRC_DIR) -name "*.c")
H_FILES := $(shell find $(INC_DIR) -name "*.h")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
INCLUDE_DIRS := $(sort $(dir $(H_FILES)))
INCLUDES := $(addprefix -I, $(INCLUDE_DIRS))

# Output binary
TARGET := ex_1_9

# Specify the VPATH
VPATH := $(SRC_DIR)

# Default target
all: $(TARGET)

# Build the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Pattern rule for object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Automatically generate dependencies
-include $(OBJ_FILES:.o=.d)

# Generate dependency files
$(OBJ_DIR)/%.d: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDES) -MM $< | sed 's,\($*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@ :,g'

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
