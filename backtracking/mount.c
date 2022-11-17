#include <stdio.h>
#include <stdbool.h>

#define MAX 20

typedef struct
{
    int m, n;

} Move;

int is_solution (int k, int lenght)
{
    return k > lenght;
}

void process_solution (int field[MAX*MAX], int m, int n, Move a[], int k, int *length)
{
    *length = k;
    
    printf ("NUOVA SEQ con K = %d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf ("(%d)", field[n*a[i].m + a[i].n]);
    }
        printf ("\n");

}

void construct_candidates (int field[MAX*MAX], int m, int n, Move a[], int k, Move c[], int *ncandidates)
{
    if (k == 0)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[j + n*i].m = i;
                c[j + n*i].n = j;

                *ncandidates += 1;
            }
        }
        for (int i = 0; i < *ncandidates; i++)

            printf ("CAND = (%d, %d). ", c[i].m, c[i].n);

        printf ("\n");
        
    }
    else
    {
        //printf ("ci sono\n");
        int q = k - 1;
        if (a[q].m < m - 1)
        {
            //printf ("M < M - 1\n");

            
            if (field[n*a[q].m + a[q].n] > field[n*(a[q].m + 1) + a[q].n])
            {
                c[*ncandidates].m = a[q].m + 1;
                c[*ncandidates].n = a[q].n;
                *ncandidates += 1;
            }
        }
        if (a[q].n < n - 1)
        {
            //printf ("N < N - 1\n");

            if (field[n*a[q].m + a[q].n] > field[n*(a[q].m) + a[q].n + 1])
            {
                c[*ncandidates].m = a[q].m;
                c[*ncandidates].n = a[q].n + 1;
                *ncandidates += 1;
            }
        }
        if (a[q].m > 0)
        {
            //printf ("M > 0\n");
            //printf ("M  0. a[q] = %d: (%d, %d)\n", q, a[q].m, a[q].n);

            if (field[n*a[q].m + a[q].n] > field[n*(a[q].m - 1) + a[q].n])
            {
                c[*ncandidates].m = a[q].m - 1;
                c[*ncandidates].n = a[q].n;
                *ncandidates += 1;
            }
        }
        if (a[q].n > 0)
        {
            //printf ("N > 0\n");

            if (field[n*a[q].m + a[q].n] > field[n*(a[q].m) + a[q].n - 1])
            {
                c[*ncandidates].m = a[q].m;
                c[*ncandidates].n = a[q].n - 1;
                *ncandidates += 1;
            }
        }
    }
    /*
    for (int i = 0; i < *ncandidates; i++)
    {
        printf ("CANDIDATO (%d, %d)   ", c[i].m, c[i].n);

    }
    printf ("\n");
    */
}

void backtrack (int field[MAX*MAX], int m, int n, Move a[], int k, int *lenght)
{
    Move c[MAX*MAX];
    int ncandidates = 0;

    //printf("INIZIO BACKTRAKING CON k = %d\n", k);

    if (is_solution (k, *lenght))
    {
        process_solution (field, m, n, a, k, lenght);
    }
    else
    {
        construct_candidates (field, m, n, a, k, c, &ncandidates);

        /*
        for (int i = 0; i < ncandidates; i++)
        {
            printf ("c:(%d, %d); Val = %d ", c[i].m, c[i].n, field[n*c[i].m + c[i].n]);
        }
        printf ("\n");
        */


        for (int i = 0; i < ncandidates; i++)
        {
            a[k].m = c[i].m;
            a[k].n = c[i].n;

            //printf ("CHIAMO IL BACK TRAKING CON k = %d; a[k] = (%d, %d)\n", k, a[k].m, a[k].n);

            k += 1;

            backtrack (field, m, n, a, k, lenght);

            k -= 1;
        }
    }

}

int main ()
{
    int field[25] = {1, 2, 3, 4, 5,
                     16, 17, 18, 19, 6,
                     15, 24, 25, 20, 7,
                     14, 23, 22, 21, 8,
                     13, 12, 11, 10, 9};

    Move a[MAX*MAX];
    
    int m = 5;
    int n = 5;
    int lenght = 0;

   //int field[50] = {56, 14, 51, 58, 88, 26, 94, 24, 39, 41, 24, 16, 8, 51, 51, 76, 72, 77, 43, 10, 38, 50, 59, 84, 81, 5, 23, 37, 71, 77, 96, 10, 93, 53, 82, 94, 15, 96, 69, 9, 74, 0, 62, 38, 96, 37, 54, 55, 82, 38};

    backtrack (field, m, n, a, 0, &lenght);

    printf ("risultato: %d", lenght);




    return 0;
}