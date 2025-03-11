OBJ = $(patsubst %.c, %.o, $(wildcard *.c))
CC = gcc

a.out : $(OBJ)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -c $^

clean :
	rm *.out *.o