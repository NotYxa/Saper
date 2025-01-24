CC = gcc
CFLAGS = -Wall -g
TARGET = minesweeper
TEST_TARGET = test

SRCS = main.c board.c game.c io.c scores.c
OBJS = $(SRCS:%.c=%.o)
TEST_SRCS = test.c board.c game.c io.c scores.c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_SRCS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRCS)
	./$(TEST_TARGET)