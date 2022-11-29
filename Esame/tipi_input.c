#include <stdio.h>
#define MAX 100

void mprint (int *matrix, int m, int n)
{
    printf ("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            printf ("%d ", matrix[i*n + j]);
        }
        printf ("\n");
    }
    printf ("\n");
}

/*
Prelevo matrice con T casi di test e dimensioni note

2
3 2
2 5
4 1
3 1
4 4
1 2 3 4
1 2 3 4
4 5 6 7
5 4 2 1

int main ()
{
    int matrix[MAX];
    int T = 0, m = 0, n = 0;

    scanf ("%d", &T);
    while (T--)
    {   
        scanf ("%d %d", &m, &n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf ("%d", &matrix[i*n + j]);
            }
        }
        mprint (matrix, m, n);
        printf ("\n");
    }


    return 0;
}
*/

//Input senza il numero di matrici che si stanno per leggere
/*
3 2
2 5
4 1
3 1
4 4
1 2 3 4
1 2 3 4
4 5 6 7
5 4 2 1

int main ()
{
    int matrix[MAX];
    int m = 0, n = 0;

    while (1) //alternativa fgets ()
    {
        char c = fgetc (stdin);

        if (c == '\n') break;
        //sscanf (buff, "%d %d", &m, &n);
        ungetc (c, stdin);

        scanf ("%d %d", &m, &n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf ("%d", &matrix[i*n + j]);
            }
        }
        char waste = fgetc (stdin);
        mprint (matrix, m, n);

    }
}
