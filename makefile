CC = gcc
FLAGS = -Wall -g

# make static library called libmyBank.a

libmyBank.a: myBank.o 
	ar -rcs libmyBank.a myBank.o 

# mains 
mains: main.o libmyBank.a
	$(CC) -Wall -g -o mains main.o libmyBank.a

# all - compile program (compile only files that have changed)

all: mains libmyBank.a

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean

# removing all .o,and mains/d (exeute) files
clean:
	rm -f *.o *.a *.so mains 