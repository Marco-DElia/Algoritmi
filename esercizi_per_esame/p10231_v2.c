#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int w, qi;

} Elephant;

Elephant vector[MAX];
int n_elepthans = 0;

int output[MAX];
int n_output = 0;

void construct_candidates (int a[], int k, int c[], int *ncandidates)
{
    if (k == 0)
    {
        for (int i = 0; i < n_elepthans; i++)
        {
            c[i] = i;
            *ncandidates += 1;
        }
    }
    else
    {
        for (int i = 0; i < n_elepthans; i++)
        {
            if (vector[a[k - 1]].w < vector[i].w && vector[a[k - 1]].qi > vector[i].qi)
            {
                c[*ncandidates] = i;
                *ncandidates += 1;
            }
        }
    }

    for (int i = 0; i < *ncandidates; i++)
    {
        printf ("%d ", c[i]);
    }
    printf ("\n");

}

void backtrack (int a[], int k)
{
    int c[MAX];
    int ncandidates = 0;

    if (k >= n_output) 
    {
        n_output = k;
        printf ("n_output = %d\n", n_output);
        for (int i = 0; i < n_output; i++)
        {
            output[i] = a[i];
            printf ("output = %d\n", output[i]);
        }
    }

    construct_candidates (a, k, c, &ncandidates);


    for (int i = 0; i < ncandidates; i++)
    {
        a[k] = c[i];
        printf ("a[k] = %d\n", a[k]);

        k++; 
        backtrack (a, k);
        k--; 

    }
}

int main ()
{
    char buffer[20];
    int a[MAX];
    int k = 0;
    
    while (fgets (buffer, sizeof (buffer), stdin) != NULL && sscanf (buffer, "%d %d", &(vector[n_elepthans].w), &(vector[n_elepthans].qi)) == 2)
    {
        n_elepthans++;
    }

    backtrack (a, k);

    for (int i = 0; i < n_output; i++)
    {
        printf ("%d\n", output[i]);
    }


    return 0;
}