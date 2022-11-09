#include <stdio.h>

#define N 9
int matrix[N][N];

struct Elem
{
    int x, y;
};

int is_a_solution (int **m)
{

}

void process_solution (int **m)
{

}

int square_is_complete (int **m, int n)
{
    int n = 0, m = 0, find = 0;

    while (!find && m < N/3)
    {
        if (m[n][m] != -1)
        {
            find = 1;
        }
        else
        {
            n++;
            if (n == N/3)
            {
                n = 0;
                m++;
            }
        }
    }
    return find;
}

int first_sub_free (int **m)
{
    int find = 0, i = 0;

    while (!find && i < 9)
    {
        if (!square_is_complete (&(m + i*N), N/3))
        {
            find = 1;
        }
        else i++;
    }

    return find == 1 ? i : -1;
}

void construct_candidates (int **m, struct Elem *c, int *ncandidates)
{
    int i = first_sub_free (m);
    if ()
}

void make_move (int **m, int **matrix, struct Elem *c, int ncandidates)
{

}



void backtrack (int **m)
{
    struct Elem c[MAXN];
    int ncandidates;

    if (is_a_solution (m))
    {
        process_solution (m);
    }
    else
    {
        construct_candidates (m, c, &ncandidates);

        for (int i = 0; i < ncandidates; i++)
        {
        
        }
    }
}


int main ()
{

    return 0;
}