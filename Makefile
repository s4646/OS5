PHONY = all clean
CC = gcc
FLAGS = -Wall -Werror -g
C++ = -lstdc++

all: main

main: main.o tasks.o queue.o activeObject.o pipeline.o
	$(CC) $^ -pthread -o main $(C++)

main.o: main.cpp
	$(CC) $(FLAGS) -c $^ $(C++)

tasks.o: tasks.cpp
	$(CC) $(FLAGS) -c $^ $(C++)

queue.o: queue.cpp
	$(CC) $(FLAGS) -c $^ $(C++)

activeObject.o: activeObject.cpp
	$(CC) $(FLAGS) -c $^ $(C++)

pipeline.o: pipeline.cpp
	$(CC) $(FLAGS) -c $^ $(C++)


clean:
	rm -f *.a *.o *.so *.gch main