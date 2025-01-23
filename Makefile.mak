CC = gcc
CFLAGS = -Wall -g
TARGET = minesweeper

all: $(TARGET)

$(TARGET): main.o board.o game.o io.o scores.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o board.o game.o io.o scores.o

main.o: main.c board.h game.h io.h scores.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c

scores.o: scores.c scores.h
	$(CC) $(CFLAGS) -c scores.c

clean:
	rm -f *.o $(TARGET)
