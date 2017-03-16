all: dinamic.c function.c vector.h
	gcc -Wall -o IntVector dinamic.c function.c