CC = g++
FLAGS = -Wall -g

username-generator: Source.o Action.o
	$(CC) $(FLAGS) -o username-generator Source.o Action.o 

Source.o: Source.cpp
	$(CC) $(FLAGS) -c -o Source.o Source.cpp

Action.o: action.cpp action.h
	$(CC) $(FLAGS) -c -o Action.o action.cpp

clean:
	$(RM) *.o
