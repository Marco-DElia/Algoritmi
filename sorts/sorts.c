#include "sorts.h"

void insertion_sort(int *vector, int n) {

    for(int i = 1; i < n; i++) {

        int j = i;
        while(vector[j] < vector[j-1] && j > 0){
            
            int swap  = vector[j];
            vector[j] = vector[j-1];
            vector[j-1] = swap;

            j--;
        }
    }
}

void insertion_sort_v2(int *vector, int n) {

    for(int i = 1; i < n; i++) {

        int key = vector[i];
        int j = i - 1;

        while(j >= 0 && key < vector[j]) {

            vector[j + 1] = vector[j];
            j--;
        }

        vector[j + 1] = key;
    }
}

void selection_sort(int *vector, int n) {

    for(int i = 0; i < n-1; i++) {

        //ricerca del minimo
        int min_idx = i;

        for(int j = i+1; j < n; j++) {

            if(vector[j] < vector[min_idx])
                min_idx = j;
        }

        if(min_idx != i) {
            int swap = vector[i];
            vector[i] = vector[min_idx];
            vector[min_idx] = swap;
        }
    }
}

/**********Implementazione Max Heap***********/


void swap(int *vector, int i1, int i2) {

    int swap   = vector[i1];
    vector[i1] = vector[i2];
    vector[i2] = swap;
}

void max_heapify(struct heap *h, int index) {

    index++;

    int left =  index * 2;
    int right = (index * 2) + 1;

    int larger = index;

    if(left <= h->heap_size && h->vector[left-1] > h->vector[index-1])

        larger = left;

    if(right <= h->heap_size && h->vector[right-1] > h->vector[larger-1])

        larger = right;

    if(larger != index) {

        swap(h->vector, larger-1, index-1);

        max_heapify(h, larger-1);

    }
}

void build_max_heap(struct heap *h, int vector_size) {

    h->heap_size = vector_size;

    //so che dopo la meta' sono tutti figli, mentre prima sono nodi

    for(int i = vector_size/2 - 1; i >= 0; i--)

        max_heapify(h, i);
}


void heap_sort(int *sorted_vector, struct heap *h) {

    build_max_heap(h, h->heap_size);

    int n = h->heap_size;

    for(int i = 0; i < n; i++) {

        sorted_vector[i] = h->vector[i];

        swap(h->vector, 0, h->heap_size - 1);     

        h->heap_size--;

        max_heapify(h, 0);
    }
}

int partition (int *v, int l, int r)
{
    int pivot = v[r];

    int i = -1;

    for (int j = 0; j < r; j++)
    {
        if (v[j] <= pivot)
        {
            i += 1;
            swap (v, i, j);
        }
    }
    swap (v, i + 1, r);

    return i + 1;
}

void quicksort (int *v, int l, int r)
{
    if (l < r)
    {
        q = partition (v, l, r);
        quicksort (v, l, q);
        quicksort (v, q + 1, l);
    }
}