PHONY = all clean
CC = gcc
FLAGS = -Wall -Werror -g

all: main

main: queue.o main.o
	$(CC) $^ -o main

main.o: main.c
	$(CC) $(FLAGS) -c main.c

queue.o: queue.c
	$(CC) $(FLAGS) -c queue.c


clean:
	rm -f *.a *.o *.so *.gch main