# Makefile Variables
CC       = gcc
EXEC    = snek
CFLAGS = -Wall -Werror -ansi -pedantic -g
OBJ      = main.o terminal.o random.o

# GOD MODE 
ifdef UNBEATABLE 
CFLAGS += -D UNBEATABLE
UNBEATABLE : clean $(EXEC)
endif



$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c main.h snek.h player.h
	$(CC) $(CFLAGS) -c main.c



terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c


clean:
	rm -f $(EXEC) $(OBJ)
