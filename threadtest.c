#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include "maMalloc.h"



void *func() {
	printf("Inside thread 1\n");
	void *p = maMalloc(50);
	void *p1 = maRealloc(p, 100);
	monFree(p);
	printf("-----Thread 1 Done----\n");
	return NULL;
}

void *func1() {
	printf("Inside thread 2\n");
	void *p = maMalloc(50);
	void *p1 = maMalloc(200);
	void *p2 = maMalloc(200);
	void *p3 = maMalloc(5000);
	void *p4 = maRealloc(p2, 300);
	
	monFree(p4);
	printf("-----Thread 2 Done----\n");
	return NULL;
}

int main() {
	pthread_t t1, t2, t3;
	pthread_create(&t1, NULL, func,  NULL);
	pthread_create(&t2, NULL, func1, NULL);
	pthread_create(&t3, NULL, func,  NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	/*Malloc_stats();*/
	return 0;
}
