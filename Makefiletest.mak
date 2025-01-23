CC = gcc
CFLAGS = -Wall -g
TARGET = minesweeper
TEST_TARGET = test

# Source files
SRCS = main.c board.c game.c io.c scores.c
# Object files
OBJS = $(SRCS:.c=.o)
# Test source files
TEST_SRCS = test.c
# Test object files
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
    rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

# Test target
test: $(TEST_TARGET)
    @echo "Running tests..."
    @./$(TEST_TARGET)

# Link the test executable
$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
    $(CC) $(CFLAGS) -o $@ $^

.PHONY: all clean test