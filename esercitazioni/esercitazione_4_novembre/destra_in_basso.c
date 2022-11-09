#include <stdio.h>

typedef struct
{
    int m, n, value;

} Move;

#define M 3
#define N 3
int matrix[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

int is_solution (Move a[], int k)
{
    return (a[k].m == M - 1 && a[k].n == N - 1);
}

void elaborate_solution (Move a[], int k)
{
    for (int i = 0; i <= k; i++)
    {
        printf ("%d ", a[i].value);
    }
    printf ("\n");
}

void construct_candidates (Move move, Move *c, int *ncandidates)
{
    *ncandidates = 0;

    if (move.m < M - 1 && move.n < N - 1)
    {
        *ncandidates = 2;
        c[0].m = move.m + 1;
        c[0].n = move.n;
        c[1].m = move.m;
        c[1].n = move.n + 1;
    }
    else if (move.m < M - 1)
    {
        //printf ("WWW\n");
        *ncandidates = 1;
        c[0].m = move.m + 1;
        c[0].n = move.n;
    }
    else if (move.n < N - 1)
    {
        //printf ("OOO\n");
        *ncandidates = 1;
        c[0].m = move.m;
        c[0].n = move.n + 1;
    }
}

void backtrack (Move a[], int k) //vettore che contiene il persorso e il numero di mosse fatte
{
    Move c[2]; //vettore delle mosse possibili (candidati)
    int ncandidates;

    if (is_solution(a, k))
    {
        elaborate_solution (a, k);
    }
    else
    {
        //printf ("(K:%d) %d, %d, %d\n",k, a[k].m, a[k].n, a[k].value);
        construct_candidates (a[k], c, &ncandidates);
        /*print candidates
        for (int q = 0; q < ncandidates; q++)
        {
            printf ("CAN: %d, %d\n", c[q].m, c[q].n);
        }
        */
        k += 1;

        for (int i = 0; i < ncandidates; i++)
        {
            a[k].m = c[i].m;
            a[k].n = c[i].n;
            a[k].value = matrix[c[i].m][c[i].n];

            backtrack (a, k);
        }
    }
}


int main ()
{
    Move a[10];
    a[0].m = 0;
    a[0].n = 0;
    a[0].value = matrix[0][0];
    backtrack (a, 0);
    
    return 0;
}