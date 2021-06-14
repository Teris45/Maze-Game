#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
# 	Pou sai re deli magka
#	Teaching programming since 1999
#
#

OBJS	= main.o Engine.o Living.o
SOURCE	= main.cpp Engine.cpp Living.cpp
HEADER	= Engine.h Living.h
OUT	= PotterMaze
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =
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


# clean house
clean:
	rm -f $(OBJS) $(OUT)