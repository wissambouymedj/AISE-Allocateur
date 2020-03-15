#include <stdio.h>   
#include <stdlib.h> 
#include"maMalloc.c"
 int main(){
//Pour la fonction maMalloc
 int *p=maMalloc(100);
 monFree(p);
//verification
 printf("Allocation et desallocation faites!\n");
//Pour la fonction maCalloc
 size_t *q =maCalloc(20,sizeof(int));
 printf("calloc et desalloc fait!\n");
 monFree(q);
//Pour la fonction //maRealloc
char * aloc = NULL;
//Allocation de la mémoire 
aloc = (char *) maMalloc( 100 * sizeof(char) );
maRealloc(aloc,100);
printf("realloc et desalloc fait!\n");
monFree(aloc);

}

