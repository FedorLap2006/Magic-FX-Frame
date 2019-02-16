all: lib

CC = g++ -std=c++14 -W
OUTDIR = 


lib:
	$(CC) -c *.cpp
	ar rc libMFF.a *.o
	rm *.o