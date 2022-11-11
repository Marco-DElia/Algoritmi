
#include <stdbool.h>
#include <stdio.h>

#define N 8

typedef struct
{
    int m, n;

} Move;


typedef struct
{
    Move queens[N];
    int placed;

} Board;


int is_solution (Board *b)
{
    return b->placed == N;
}

void compute_solution (int *result)
{
    (*result)++;
}

void discard (bool m[N][N], Move queen)
{
    for (int i = 0; i < N; i++) m[i][queen.n] = 0;
    for (int j = 0; j < N; j++) m[queen.m][j] = 0;

    int i = queen.m;
    int j = queen.n;
    while (i < N && j < N)
    {
        m[i][j] = 0;
        i++;
        j++;
    }

    i = queen.m;
    j = queen.n;
    while (i >= 0 && j >= 0)
    {
        m[i][j] = 0;
        i--;
        j--;
    }

    i = queen.m;
    j = queen.n;
    while (i >= 0 && j < N)
    {
        m[i][j] = 0;
        i--;
        j++;
    }

    i = queen.m;
    j = queen.n;
    while (i < N && j >= 0)
    {
        m[i][j] = 0;
        i++;
        j--;
    }
}

void construct_candidates (Board *b, Move c[], int *ncandidates)
{
    bool m[N][N];

    // Tutte le posizioni inizialmente consentite
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m[i][j] = 1;
        }
    }
   
    // Scarto le posizioni occupate o attaccate dalle regine
    for (int q = 0; q < b->placed; q++)
    {
        discard (m, b->queens[q]);
    }

    // Salvo le mosse possibili
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (m[i][j] == 1 && b->placed != 0 && (j + i * (N)) > (b->queens[b->placed - 1].n + b->queens[b->placed - 1].m * (N)))
            {
                c[*ncandidates].m = i;
                c[*ncandidates].n = j;
            
                *ncandidates += 1;
            }
            else if (b->placed == 0)
            {
                c[*ncandidates].m = i;
                c[*ncandidates].n = j;
            
                *ncandidates += 1;
            }
            
        }
    }
}

void backtrack (Board *b, int *result)
{
    Move c[N*N];
    int ncancidates = 0;

    if (is_solution (b))
    {
        compute_solution (result);
    }
    else
    {
        construct_candidates (b, c, &ncancidates);

        for (int i = 0; i < ncancidates; i++)
        {
            b->queens[b->placed].m = c[i].m;
            b->queens[b->placed].n = c[i].n;

            b->placed += 1;

            backtrack (b, result);

            b->placed -= 1;
        }
    }
}


int main ()
{

    Board b;
    b.placed = 0;
    int result = 0;

    backtrack (&b, &result);

    printf ("Result: %d\n", result);
    return 0;
}