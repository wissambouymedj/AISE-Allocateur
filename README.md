# AISE-Allocateur

donc le fichier source (maMalloc.c )
on a implémenté les fonctions suivantes : maMalloc , maRealloc , maCalloc et monFree 
en utilisant  l'allocation de page via  « mmap » et « munmap »

le test de performance : test1.c 
comparaison de notre allocateur à celui de système 


Multithreading :threadtest.c 
Pour résoudre le problème de concurrence , on a utilisé une mécanisme de synchronisation : Mutex

Compilation et exécution :
Pour générer la bibliothèque dynamique (libmalloc.so), on compile le code source (maMalloc.c)
avec l’option fPIC et elle se réalise en appellant gcc avec l’option « shared »
