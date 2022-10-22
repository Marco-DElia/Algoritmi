#ifndef _SORTS_
#define _SORTS_

void insertion_sort(int *vector, int n);
void insertion_sort_v2(int *vector, int n);
void selection_sort(int *vector, int n);


//max heap

#define MAX_SIZE 100

struct heap {

    int vector[MAX_SIZE];
    int heap_size;

};

void max_heapify(struct heap *h, int index);
void build_max_heap(struct heap *h, int vector_size);
void heap_sort(int *sorted_vector, struct heap *h);



#endif