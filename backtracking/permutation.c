#include <stdio.h>

#define MAXN 10

int is_solution (int k, int n)
{
    return k == n; // n - 1 ???
}

void elaborate_solution (int a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        printf ("%d", a[i]);
    }
    printf ("\n");
}

int is_in (int a[], int k, int e)
{
    int i = 0;
    while (i < k && a[i] != e)
    {
        i++;
    }

    return i == k ? 0 : 1;
}

void construct_candidates (int a[], int k, int n, int c[], int *ncandidates)
{
    *ncandidates = 0;

    for (int i = 0; i < n; i++)
    {
        if (! is_in(a, k, i + 1))
        {
            c[*ncandidates] = i + 1;
            *ncandidates += 1;
        }
    }
}

//questa funzione non va
void construct_candidates_opt(int a[], int k, int n, int c[], int *ncandidates)
{
    *ncandidates = 0;

    int bools[MAXN]; //vettore con 0 se il numero (i+1) è assente, 1 se presente

    for (int i = 0; i < n; i++) bools[i] = 0; // assumo che nessun elemento ci sia

    for (int i = 0; i < k; i++) bools[a[i] - 1] = 1; // metto a 1 in posizione data da a - 1 (per tutti gli elementi di a)

    for (int i = 0; i < n; i++) //per tutti gli n, se il valore (i+1) non è presente è un candidato, altimenenti no
    {
        if (bools[i] == 0) //il valore (i+1) è assente in a
        {
            c[i] = i + 1;
            *ncandidates += 1;
        }
    }
}


void backtracking (int a[], int k, int n)
{
    int c[MAXN];
    int ncandidates;

    if (is_solution (k, n))
    {
        elaborate_solution (a, k);
    }
    else
    {
        construct_candidates (a, k, n, c, &ncandidates);
        k += 1;

        for (int i = 0; i < ncandidates; i++)
        {
            a[k - 1] = c[i];
            backtracking (a, k, n);
        }
    }
}

void permutation (int n)
{
    int a[MAXN];
    backtracking (a, 0, n);
}

int main ()
{
    permutation (5);
    return 0;
}