#ifndef MALLOC_H
# define MALLOC_H
#include <stdlib.h>
#include "maMalloc.c"



void * maMalloc(size_t taille);
void* maCalloc(size_t nombre, size_t taille);
void* maRealloc(void * memoire, size_t taille);
void monFree(void * ptr);

#endif /* MALLOC_H */
