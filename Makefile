#Sample Makefile for Malloc
CC=gcc
CFLAGS=-g -O0 -fPIC

all: check

clean:
	rm -rf libmalloc.so test1 maMalloc threadtest test *.o

test: test1.c  maMalloc.c 
	gcc -g -o $@ $^ -lm

threadtest: threadtest.c
	gcc -g -o $@ $^ -lm -lpthread

test-run: test
	./test

maMalloc: maMalloc.c 
	gcc $(CFLAGS) -c $^

lib: maMalloc.o 
	$(CC) -shared -o libmalloc.so $^ -lm

test1: test1.o 
	$(CC) $(CFLAGS) $< -o $@

t-test1: t-test1.o
	$(CC) $(CFLAGS) $< -o $@ -lpthread

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ -lm -lpthread


check: lib test1 threadtest 
	LD_PRELOAD=`pwd`/libmalloc.so ./test1
	LD_PRELOAD=`pwd`/libmalloc.so ./threadtest


dist: clean
	dir=`basename $$PWD`; cd ..; tar cvf $$dir.tar ./$$dir; gzip $$dir.tar