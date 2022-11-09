#include <stdio.h>

#define MAXCANDIDATES 2
#define NMAX 10

int is_a_solution (int k, int n)
{
    return k == n ? 1 : 0;
}

void process_solution (int a[], int k)
{
    printf ("{");
    for (int i = 0; i <= k; i++)
    {
        if (a[i] == 1) printf ("%d", i + 1);
    }
    printf ("}, ");
}

void contruct_candidates (int c[], int *ncandidates)
{
    c[0] = 0;
    c[1] = 1;
    *ncandidates = 2;
}

void make_move (int a[], int k, int c[], int i)
{
    a[k] = c[i];
}

/*
void unmake_move (int a[], int k, int c[], int ncandidates, int i)
{

}
*/

void backtrack (int a[], int k, int n)
{
    int c[MAXCANDIDATES];
    int ncandidates;


    if (is_a_solution (k, n))
    {
        process_solution (a, k);
    }
    else
    {
        k += 1;
        contruct_candidates (c, &ncandidates);

        for (int i = 0; i < ncandidates; i++)
        {
            //printf ("(k:%d, i:%d) ", k, i);
            a[k - 1] = c[i];
            //make_move (a, k, c, i);
            backtrack (a, k, n);
            //unmake_move (a, k);
        }
    }
}

void generate_subsets (int n)
{
    int a[NMAX];

    backtrack (a, 0, n);
}

int main ()
{

    generate_subsets (3);

    return 0;
}