#include "sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int v[] = {98, 13, 17, 49, 31, 20, 62, 15, 8, 72};

    quicksort (v, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf ("%d ", v[i]);
    }

    /*
    struct heap h;
    int n = 10;

    srand(time(0));
    
    for(int i = 0; i < n; i++) {

        //h.vector[i] = rand() % 100;
        h.vector[i] = v[i];
        printf("%d  ", h.vector[i]);
    }

    printf("\n");

    build_max_heap(&h, n);

    for(int i = 0; i < h.heap_size; i++)

        printf("%d  ", h.vector[i]);

    printf("\n");
    

    int vector[100];

    int k = h.heap_size;

    heap_sort(vector, &h);

    for(int i = 0; i < k; i++)

        printf("%d  ", vector[i]);

    printf("\n");


/*
    insertion_sort(v, 6);
    for(int i = 0; i < 6; i++)
        printf("%d", v[i]);

    printf("\n");

    insertion_sort_v2(v, 6);
    for(int i = 0; i < 6; i++)
        printf("%d", v[i]);
    
    printf("\n");

    selection_sort(v, 6);
    for(int i = 0; i < 6; i++)
        printf("%d", v[i]);

*/
    return 0;
}