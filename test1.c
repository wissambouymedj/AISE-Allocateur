#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "maMalloc.h"

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main(void)
{
   struct timeval t0 , d0;
   struct timeval t1 , d1; 
   float elapsed;


 int* p = NULL;
    gettimeofday(&t0, 0);
    p = maMalloc(sizeof(int)); // Allocation de la mémoire avec maMalloc 
    gettimeofday(&t1, 0);

   elapsed = timedifference_msec(t0, t1);

   printf("Code executé avec maMalloc en: %f millisecondes.\n", elapsed);  

int* q = NULL;
    gettimeofday(&d0, 0);
    q = malloc(sizeof(int)); // Allocation de la mémoire avec malloc du systeme
    gettimeofday(&d1, 0);

   elapsed = timedifference_msec(d0, d1);

   printf("Code executé avec malloc du systéme en: %f millisecondes.\n", elapsed); 
    
if (p == NULL)
    {
        exit(0);
    }

    monFree(p); // Libération de mémoire avec monFree


  if (q == NULL)
    {
        exit(0);
    }

    free(q); // Libération de mémoire avec free du systeme

   
   return 0;
}

