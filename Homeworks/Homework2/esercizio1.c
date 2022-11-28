#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int m, n;

} Point;

void mprint (int *mtr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf ("%d ", mtr[i*n + j]);
        }
        printf ("\n");
    }
}

void transform_matrix (int *inm, int *outm, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((inm[i*n + j] == 0)                           ||
                (i > 0      && inm[(i - 1)*n + j    ] == 0)   ||
                (i < m - 1  && inm[(i + 1)*n + j    ] == 0)   ||
                (j > 0      && inm[i*n       + j - 1] == 0)   ||
                (j < n - 1  && inm[i*n       + j + 1] == 0))
           
                    outm[i*n + j] = 0;

            else    outm[i*n + j] = inm[i*n + j];
        }
    }
}

bool inline connected (int *mtr, int m, int n, Point *a, Point *b)
{
    return (mtr[b->m*n + b->n]) && ((a->m + 1 == b->m) || (a->n + 1 == b->n) || (a->m - 1 == b->m) || (a->n - 1 == b->n));
}

void connected_list (int *m, Point *a, Point *b, Point list[], int *nconnected)
{
    for ()
}

int lowest_track (int *mtr, int memo, int m, int n, Point *s, Point *d)
{
    if  (connected (mtr, m, n, s, d)) return 1; //assumo di partire dal nodo 's' che è valido
    /*else
    {
        //for ()
    }
    */
   else return 0;
}


int main ()
{
    /*int mtr[][5] = { {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1}};

    int m = 5, n = 5;

    Point a = (Point) {0, 0};
    Point b = (Point) {1, 0};

    printf ("%d\n", connected ((int *)mtr, m, n, &a, &b));
    */

    /*
    int (*outmtr)[5];
    int newmtr[5][5] = {};

    mprint (mtr, m, n);
    printf ("***********\n");

    mprint(newmtr, m, n);
    printf ("***********\n");
    
    transform_matrix (mtr, newmtr, m, n);
    mprint (newmtr, m, n);
    */

   printf ("ciaooo\n");

}