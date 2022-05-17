# Makefile Variables
CC       = gcc
EXEC    = snake
CFLAGS = -Wall -Werror -ansi -pedantic -g
OBJ      = main.o game.o map.o mem.o output.o snake.o snakeio.o random.o

# GOD MODE 
ifdef UNBEATABLE 
CFLAGS += -D UNBEATABLE
UNBEATABLE : clean $(EXEC)
endif



$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c main.h game.h constants.h
	$(CC) $(CFLAGS) -c main.c

game.o : game.c game.h snake.h mem.h constants.h snakeio.h random.h output.h 
	$(CC) $(CFLAGS) -c game.c

map.o : map.c map.h constants.h mem.h snake.h
	$(CC) $(CFLAGS) -c map.c

mem.o : mem.c mem.h snake.h 
	$(CC) $(CFLAGS) -c mem.c

output.o : output.c output.h maps.h
	$(CC) $(CFLAGS) -c output.c

snake.o : snake.c snake.h
	$(CC) $(CFLAGS) -c snake.c

snakeio.o : snakeio.c snakeio.h mem.h snake.h
	$(CC) $(CFLAGS) -c snakeio.c

#terminal.o: terminal.c terminal.h
#	$(CC) $(CFLAGS) -c terminal.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c


clean:
	rm -f $(EXEC) $(OBJ)
