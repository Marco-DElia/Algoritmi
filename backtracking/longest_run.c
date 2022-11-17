/*
#define MAX_SIZE 100

typedef struct
{
    int m, n;
} Move;

typedef struct
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int m, n;
    Move run[MAX_SIZE*MAX_SIZE];
    int nmoves;
    char name[MAX_SIZE];

} Field;

void elaborate_candidates (Field *f, Move c[], int *ncandidates)
{
    //int diff[MAX_SIZE*MAX_SIZE];
    if (f->nmoves == 0)
    {
        for (int i = 0; i < f->m; i++)
        {
            for (int j = 0; j < f->n; j++)
            {
                c[*ncandidates] = 
            }
        }
    }
    
}

void backtrack (Field *f)
{
    Move c[MAX_SIZE*MAX_SIZE];
    int ncandidates = 0;

    if (is_solution (f))
    {
        compute_solution (f);
    }
    else
    {
        elaborate_candidates (f, c, &ncandidates);

        for (int i = 0; i < ncandidates; i++)
        {
            f->run[f->nmoves].m = c[i].m;
            f->run[f->nmoves].n = c[i].n;

            f->nmoves++;
            backtrack (f);
            f->nmoves--;
        }
    }
}
*/

#include <stdio.h>
#include <string.h>

#define MAX 20

void input_read (int matrix[MAX][MAX])
{
    int ninputs, m, n;
    char buff[100];
    fscanf (stdin, "%d", &ninputs);

    for (int i = 0; i < ninputs; i++)
    {
        fscanf (stdin, "%s %d %d", buff, &m, &n);
        
        for (int k = 0; k < m; k++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf (stdin, "%d", &matrix[k][j]);
            }
        }

        //backtrack
        printf ("NINPUTS: %d, BUFFER: %s\n", ninputs, buff);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf ("%d ", matrix[i][j]);
            }
                printf ("\n");
        }
        printf ("\n");

    }
}

int main ()
{

    int matrix[MAX][MAX];

    input_read (matrix);

    return 0;
}