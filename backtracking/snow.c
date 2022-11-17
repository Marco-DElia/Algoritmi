#include <stdio.h>
#include <stdbool.h>

#define MAX 20

/*int matrix[MAX][MAX] = {{1, 2, 3, 4, 5},
                        {16, 17, 18, 19, 6},
                        {15, 24, 25, 20, 7},
                        {14, 23, 22, 21, 8},
                        {13, 12, 11, 10, 9}};
    
int m = 5;
int n = 5;
*/
int matrix[MAX][MAX] = {{56, 14, 51, 58, 88},
                        {26, 94, 24, 39, 41},
                        {24, 16, 8, 51, 51},
                        {76, 72, 77, 43, 10},
                        {38, 50, 59, 84, 81},
                        {5, 23, 37, 71, 77},
                        {96, 10, 93, 53, 82},
                        {94, 15, 96, 69, 9},
                        {74, 0, 62, 38, 96},
                        {37, 54, 55, 82, 38}};
int m = 10;
int n = 5;
char buff[100];

typedef struct
{
    int n, m;
} Move;

bool is_solution (int k, int *lenght)
{
    return k > *lenght;
}

void elaborate_solution (Move a[], int k, int *lenght)
{
    *lenght = k;

    for (int i = 0; i < k; i++)
    {
        printf ("(%d) ", matrix[a[i].m][a[i].n]);
    }
    printf ("\n");
}


void construct_candidates (Move a, Move c[], int *ncandidates)
{
    if (a.m < m - 1 && matrix[a.m][a.n] > matrix[a.m + 1][a.n])
    {
        c[*ncandidates].m = a.m + 1;
        c[*ncandidates].n = a.n;
        *ncandidates += 1;
    }
    if (a.n < n - 1 && matrix[a.m][a.n] > matrix[a.m][a.n + 1])
    {
        c[*ncandidates].m = a.m;
        c[*ncandidates].n = a.n + 1;
        *ncandidates += 1;
    }
    if (a.m > 0 && matrix[a.m][a.n] > matrix[a.m - 1][a.n])
    {
        c[*ncandidates].m = a.m - 1;
        c[*ncandidates].n = a.n;
        *ncandidates += 1;
    }
    if (a.n > 0 && matrix[a.m][a.n] > matrix[a.m][a.n - 1])
    {
        c[*ncandidates].m = a.m;
        c[*ncandidates].n = a.n - 1;

        *ncandidates += 1;
    }
}


void backtrack (Move a[], int k, int *length)
{
    int ncandidates = 0;
    Move c[4];

    /*if (is_solution (k, length))
    {
        elaborate_solution (a, k, length);
    }
    else*/
    if (k > *length)
    {
        *length = k;

        for (int i = 0; i < k; i++)
        {
            printf ("(%d) ", matrix[a[i].m][a[i].n]);
        }
        printf ("\n");
    }

    construct_candidates (a[k - 1], c, &ncandidates);

    for (int i = 0; i < ncandidates; i++)
    {
        a[k].m = c[i].m;
        a[k].n = c[i].n;
        k++;
        backtrack (a, k, length);
        k--;
    }
}

void run ()
{
    int lenght = 0;
    Move a[MAX * MAX];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[0].m = i;
            a[0].n = j;
            backtrack (a, 1, &lenght);
        }
    }

    printf ("%s: %d\n", buff, lenght);
    
}

int main ()
{

    int numero_di_input;
    scanf ("%d", &numero_di_input);

    while (numero_di_input--)
    {
        scanf ("%s %d %d", buff, &m, &n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf ("%d", &matrix[i][j]);
            }
        }

        run ();

    }

    /*
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }

    run ();
    */

    return 0;
}