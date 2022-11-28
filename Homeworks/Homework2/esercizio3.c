/*
                Emanuele d'Ajello - Marco D'Elia
                       Problema 3 - Homework 2

    Trovare l'area della più grande sottomatrice di zeri in una matrice binaria.

    L'algoritmo di risoluzione si divide in due passi:
    1) Calcolo di una nuova matrice (calcolata con la funzione tooth_saw_matrix(...))
       secondo quanto illustrato:

       Matrice di input                              Matrice a 'dente di sega'
       1 0 1 1 1 0 0                                 0 1 2 0 0 1 2
       1 1 1 1 0 0 0  -- tooth_saw_matrix(...)--->>> 0 0 0 0 1 2 3
       0 0 0 0 1 0 0                                 1 2 3 4 0 1 2

    2) Per ogni colonna della matrice calcolata in precedenza, si applica un algoritmo
       per la ricerca del maggior 'rettangolo' inscritto in una rappresentazione
       grafica della colonna. Si ritorna come valore massimo, la massima area tra
       le aree dei rettangoli incritti nelle singole colonne.

       Esempio:
       Per la colonna 6 della matrice calcolata, si ha
       c[index] ^
               3|   ___
               2|__|  |___                      in questo caso è possibile inscrivere un rettangolo
               1|  |  |  |                      di area massima 6, scegliedo altezza 2 e base lunga 3.
               0|  |  |  |________
                |---------------------->
                 0  1  2  3  4        index
*/

#include <stdio.h>
#include <stdlib.h>

void mprint (int* matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf ("%d ", matrix[i*n + j]);
        }
        printf ("\n");
    }
}

void tooth_saw_matrix (int *matrix, int *newmatrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[n*i + j] == 0)
            {
                if (j == 0) newmatrix[n*i] = 1;
                else newmatrix[n*i + j] = newmatrix[n*i + j-1] + 1;
            }
            else newmatrix[n*i + j] = 0;
        }
    }
}

int maxsub (int *newmatrix, int m, int n)
{
    int max_area = 0, area = 0, tos = 0, stack_size = 0, i = 0;

    int *stack = malloc (sizeof (int) * m);

    if (stack == NULL)
    {
        printf ("ERROR in malloc maxsub\n");
        return -1;
    }

    for (int j = 0; j < n; j++)
    {
        i = 0;
        area = 0;
        tos = 0;
        stack_size = 0;

        while (i < m)
        {
            if (stack_size == 0 || newmatrix[n*stack[stack_size - 1] + j] <= newmatrix[n*i + j])
            {
                stack[stack_size] = i;

                stack_size++;
                i++;

                //printf ("PUSH -> tos: %d, newmatrix[tos]: %d, newmatrix: %d\n", stack[stack_size - 1], newmatrix[n*stack[stack_size - 1] + j], newmatrix[n*(i-1) + j]);
            }
            else
            {
                tos = stack[stack_size - 1];
                stack_size--;

                //printf ("POP -> tos: %d, newmatrix:%d\n", tos, newmatrix[n*tos + j]);
                area = newmatrix[n*tos + j] * (stack_size == 0 ? i : i - stack[stack_size - 1] - 1);
                //printf ("area: %d\n", area);
            }

            if (area > max_area) max_area = area;
        }
        //printf ("\nfine prima colonna !!!!\n");

        while (stack_size != 0)
        {
            //printf ("stack[stack_size - 1] = %d\n", stack[stack_size - 1]);
            tos = stack[stack_size - 1];
            stack_size--;
            area = newmatrix[n*tos + j] * (stack_size == 0 ? i : i - stack[stack_size - 1] - 1);

            if (area > max_area) max_area = area;
        }

    }
    return max_area;
}


int exec (int *matrix, int m, int n)
{
    int *newmatrix = malloc (sizeof (int) * (m) * (n));

    if (newmatrix == NULL)
    {
        printf ("ERROR in malloc exec\n");
        return -1;
    }

    tooth_saw_matrix (matrix, newmatrix, m, n);
    //mprint (newmatrix, m, n);
    int area = maxsub (newmatrix, m, n);

    free (newmatrix);

    return area;
}

int main ()
{
/*
Copiare ed incollare nel terminale per effettuare il testing: 5 casi di test forninti.
5
6 8
1 0 0 1 1 0 1 0 
1 1 1 1 0 0 1 0 
0 0 1 0 0 1 1 0 
0 1 1 0 1 1 1 1 
0 0 0 1 0 0 0 0 
1 0 0 1 1 1 0 1
10 6
0 0 0 1 1 0
1 0 1 0 1 1
0 0 0 1 0 1
1 1 0 1 1 1
0 1 0 0 1 1
0 0 1 1 1 1
1 0 1 0 0 0
1 0 0 1 0 1
0 0 1 1 0 0
0 1 0 0 1 1
6 9
1 0 1 0 1 0 1 1 0
0 1 1 1 1 0 0 0 1
1 0 1 0 1 0 0 0 1
0 0 1 1 0 0 0 0 0
1 0 1 1 0 0 0 1 1
0 0 1 0 1 1 1 1 1
8 4
1 0 1 0
1 1 0 0
0 1 0 1
0 0 1 1
1 0 1 1
0 0 1 1
1 1 0 0
1 0 0 0
4 10
1 1 1 0 0 1 0 1 0 0 
1 1 1 0 1 1 0 1 0 1
1 0 1 1 0 0 0 0 1 1
0 1 0 1 0 0 0 0 0 1
*/

    int *matrix = NULL;
    int m = 0, n = 0, T = 0;


    scanf ("%d", &T);

    while (T--)
    {
        scanf ("%d %d", &m, &n);

        matrix = malloc (sizeof (int) * m * n);

        if (matrix == NULL)
        {
            printf ("Error in malloc (main)\n");
            return -1;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf ("%d", &matrix[i*n + j]);
            }
        }
        printf ("RISULTATO: %d\n", exec (matrix, m, n));

    }

    return 0;
}