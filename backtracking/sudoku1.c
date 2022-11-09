#include <stdio.h>

#define N 9
#define MAXMOVES N*N

typedef struct
{
    int x, y;

} Move;

typedef struct
{
    int m[N][N];
    int moves[MAXMOVES];
    int remaning_moves;
} Board;

void possible_numbers (Board *b, Move move, int *candidates, int *ncandidates)
{

}

void vdelete (int *v, int e)
{
    int i = 0;
    while (v[i] != e && i < N)
    {
        i++;
    }

    if (i < N) v[i] = 0;
}

// Funzione per la costruzione di alternative
void construct_candidates (Board *b, Move *candidates, int* ncandidates)
{
    // Trovo la prmima casella libera e ne prendo i candidati
    // Salvo la mossa in board

    int i = 0, j = 0, find = 0;
    Move move;

    while (b->m[i][j] != 0 && i < N)
    {
        j++;
        if (j == N)
        {
            i++;
            j = 0;
        }
    }

    if (i == N)
    {
        *ncandidates = 0;
        return;
    }

    move.x = i;
    move.y = j;

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int k = 0; k < N; k++)
    {
        if (b->m[k][j] != 0)
        {
            vdelete (numbers, b->m[k][j]);
        }
    }   

    for (int k = 0; k < N; k++)
    {
        if (b->m[i][k] != 0)
        {
            vdelete (numbers, b->m[i][k]);
        }
    }

    
}

int main ()
{
    return 0;
}