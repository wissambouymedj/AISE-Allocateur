#define _GNU_SOURCE
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define DIV_ROUND_UP( a,  b) (((a)+(b)-1)/(b))
#define alignas(x) (((((x)-1)>>2)<<2)+4)
pthread_mutex_t lock;

void * maMalloc(size_t taille) {
pthread_mutex_lock(&lock); 
 
 size_t nvtaille = taille + sizeof(size_t);
  int pgtaille = getpagesize();
  int numdepage = DIV_ROUND_UP(nvtaille, pgtaille);
  void * nvregion = mmap(0 ,2000, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, 0, 0);
  if (nvregion == MAP_FAILED) 
  return NULL;

  *(size_t*)nvregion = nvtaille; 
pthread_mutex_unlock(&lock); 
  return nvregion+sizeof(size_t);
}

void* maCalloc(size_t nombre, size_t taille){
    size_t  *appel;
    appel = maMalloc((int)nombre * taille);
pthread_mutex_lock(&lock);
    size_t  alig,i;
    if(appel) {
        alig = alignas(nombre * taille) << 2;
        for(i=0; i<alig ; i++)
        appel[i] = 0;
    }
 pthread_mutex_unlock(&lock); 
        return (appel);
}

void* maRealloc(void * memoire, size_t taille) {
	void *call = maMalloc(taille);
pthread_mutex_lock(&lock); 
	 if(call) { 
             memcpy(call, memoire, taille); 
                   }
 pthread_mutex_unlock(&lock); 
             return call;

	}
void monFree(void * ptr) {
  void* block = ptr-sizeof(size_t);
pthread_mutex_lock(&lock); 
  if (munmap(block, *(size_t*)block) != 0) {
    printf("munmap impossible\n");
  }
  pthread_mutex_unlock(&lock); 
}

