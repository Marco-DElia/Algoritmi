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

//Input senza il numero di matrici che si stanno per leggere (ALTRO MODO)
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
    char buffer[64];

    while (fgets (buffer, 32, stdin) && buffer[0] != '\n')
    {
        sscanf (buffer, "%d %d", &m, &n);

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
*/

/*
2
40 40
80


5
10 2 6 8 4
10
Input con una serie di \n in mezzo e con carattere terminatore EOF*/
int main ()
{
    int books[100];
    int n = 0;
    int cash = 0;
    int b1, b2;
    //solve (books, 5, 10, &b1, &b2);
    //printf ("%d %d\n", b1, b2);

    char buff[64];

    while (1)
    {
        while (fgets (buff, 24, stdin) && buff[0] == '\n');
        
        if (buff[0] == 'O') break;

        sscanf (buff, "%d", &n);
        //printf ("DIMENSIONE %d\n", n);

        for (int i = 0; i < n; i++)
        {
            scanf ("%d\n", &books[i]);
        }
        scanf ("%d", &cash);
        
        for (int i = 0; i < n; i++)
            printf ("%d ", books[i]);

        printf ("\n");
    }


    return 0;
}
