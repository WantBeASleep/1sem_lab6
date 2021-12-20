SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

all:
	gcc -c $(SRC)
	gcc -o lab6 $(OBJ)
	rm *.o