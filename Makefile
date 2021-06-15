#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
# 	Pou sai re deli magka
#	Teaching programming since 1999
#
#

OBJS	= main.o Engine.o Living.o Moving.o Gem.o HighScore.o
SOURCE	= main.cpp Engine.cpp Living.cpp Moving.cpp Gem.cpp HighScore.cpp
HEADER	= Engine.h Living.h Moving.h Gem.h HighScore.h
OUT	= PotterMaze
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = -lncurses
# -g option enables debugging mode
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

Engine.o: Engine.cpp
	$(CC) $(FLAGS) Engine.cpp -std=c++14


Living.o: Living.cpp
	$(CC) $(FLAGS) Living.cpp -std=c++14

Moving.o: Moving.cpp
	$(CC) $(FLAGS) Moving.cpp -std=c++14

Gem.o: Gem.cpp
	$(CC) $(FLAGS) Gem.cpp -std=c++14


HighScore.o: HighScore.cpp
	$(CC) $(FLAGS) HighScore.cpp -std=c++14

# clean house
clean:
	rm -f $(OBJS) $(OUT)


run:
	./PotterMaze maze.txt mybin.bin
