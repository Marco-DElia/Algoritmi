#include <stdio.h>
#include <stdbool.h>


int matrix[9][9] = {{ 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                    { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                    { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                    { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
                    { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
                    { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                    { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
                    { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                    { 7, 4, 5, 0, 8, 6, 3, 1, 0 }};

typedef struct
{
    int m, n;
} Move;

bool is_solution (Move a) // da modificare inserendo un controllo sul fatto che ci siano delle posizioni libere
{
    Move b;
    do
    { 
        b.n = (a.n + 1) % 9;

        if (b.n == 0)
            b.m = a.m + 1;
        else
            b.m = a.m;
        
        //printf ("%d, %d\n", b.m, b.n);
        
        a.m = b.m;
        a.n = b.n;
    
    }while ( !(b.m == 9 && b.n == 0) && matrix[b.m][b.n] != 0);


    if ((b.m == 9 && b.n == 0)) return true;
    else return false;
}

void compute_solution ()
{
    printf ("\nSOLUZIONE:\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }
    printf ("\n\n");
}

void make_move (Move b, int c)
{
    if (b.m < 9 && b.n < 9) matrix[b.m][b.n] = c;
}

void unmake_move (Move b)
{
    if (b.m < 9 && b.n < 9) matrix[b.m][b.n] = 0;
}

void construct_candidates (Move a, Move *b, int c[], int *ncandidates)
{
    // devo trovare la prossima posizione libera (non nulla)
    if (a.m != 0 || a.n != 0 || matrix[a.m][a.n] != 0)
    {
        do
        { 
            b->n = (a.n + 1) % 9;

            if (b->n == 0)
                b->m = a.m + 1;
            else
                b->m = a.m;
            
            a.m = b->m;
            a.n = b->n;
        
        }while ( !(b->m == 9 && b->n == 0) && matrix[b->m][b->n] != 0);

        if ((b->m == 9 && b->n == 0)) return;
    }
    else
    {
        b->m = 0;
        b->n = 0;
    }

    //ho la posizione nella quale va posizionato il prossimo numero, procedo
    bool bools[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for (int i = 0; i < 9; i++) bools[matrix[b->m][i]] = false;
    for (int i = 0; i < 9; i++) bools[matrix[i][b->n]] = false;

    int i, j;
    if (b->m >= 0 && b->m <= 2) i = 0;
    else if (b->m >= 3 && b->m <= 5) i = 3;
    else i = 6;
        
    if (b->n >= 0 && b->n <= 2) j = 0;
    else if (b->n >= 3 && b->n <= 5) j = 3;
    else j = 6;

    for (int k = 0; k < 3; k++)
    {
        for (int q = 0; q < 3; q++)
        {
            bools[matrix[k + i][q + j]] = false;
        }
    }

    for (int k = 1; k < 10; k++)
    {
        if (bools[k])
        {
            c[*ncandidates] = k;
            *ncandidates += 1;
        }
    }

    //for (int k = 0; k < *ncandidates; k++) printf ("%d ", c[k]);
}

// a[] mantiene le mosse fatte
void backtrack (Move a)
{
    int c[9];
    int ncandidates = 0;
    Move b;

    if (is_solution (a))
    {
        compute_solution ();
    }
    else
    {
        construct_candidates (a, &b, c, &ncandidates); // 'a' posizione attuale, 'b' posizione prossima, 'c' candidati

        for (int i = 0; i < ncandidates; i++)
        {
           /* b.n = (a.n + 1) % 9;

            if (b.n == 0)
                b.m = a.m + 1;
            else
                b.m = a.m;
            */
            make_move (b, c[i]); // pongo la casella 'b' al valore c[i]
            backtrack (b); //riempio la casella 'b'
            unmake_move (b); //pongo la casella 'b' a 0
        }
    }
}

void solve ()
{
    Move a;
    a.m = 0;
    a.n = 0;

    backtrack (a);
}

int main ()
{
    int T = 0;
    scanf ("%d", &T);

    while (T--)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                scanf ("%d", &matrix[i][j]);
            }
        }

        solve ();
    }


}