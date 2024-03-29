# Makefile Variables
CC       = gcc
EXEC    = snake
CFLAGS = -Wall -Werror -ansi -pedantic
OBJ      = main.o game.o map.o mem.o input.o output.o snake.o snakeio.o random.o movement.o terminal.o objects.o LinkedList.o

# GOD MODE 
ifdef UNBEATABLE 
CFLAGS += -D UNBEATABLE
UNBEATABLE : clean $(EXEC)
endif



$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c main.h LinkedList.h map.h game.h constants.h
	$(CC) $(CFLAGS) -c main.c

game.o : game.c game.h mem.h LinkedList.h snake.h map.h constants.h snakeio.h random.h output.h input.h movement.h objects.h
	$(CC) $(CFLAGS) -c game.c

map.o : map.c map.h constants.h LinkedList.h mem.h snake.h random.h
	$(CC) $(CFLAGS) -c map.c

mem.o : mem.c mem.h LinkedList.h
	$(CC) $(CFLAGS) -c mem.c

input.o : input.c input.h terminal.h constants.h 
	$(CC) $(CFLAGS) -c input.c

output.o : output.c output.h LinkedList.h map.h
	$(CC) $(CFLAGS) -c output.c

snake.o : snake.c snake.h
	$(CC) $(CFLAGS) -c snake.c

movement.o : movement.c movement.h LinkedList.h mem.h snake.h map.h constants.h
	$(CC) $(CFLAGS) -c movement.c

objects.o : objects.c objects.h LinkedList.h snake.h map.h constants.h 
	$(CC) $(CFLAGS) -c objects.c

snakeio.o : snakeio.c snakeio.h LinkedList.h snake.h constants.h
	$(CC) $(CFLAGS) -c snakeio.c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c

LinkedList.o: LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c


clean:
	rm -f $(EXEC) $(OBJ)
