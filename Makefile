CC = gcc
SRC_DIR = src
INC_DIR = include
TARGET = easyc

# Find all .c source files in src and include directories
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(INC_DIR)/*.c)

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

# Link object files into final binary
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# Compile .c files into .o files
%.o: %.c
	$(CC) -c -I$(INC_DIR) $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o $(INC_DIR)/*.o

.PHONY: all clean
