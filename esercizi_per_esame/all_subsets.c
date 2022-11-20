#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int n;

void construct_candidates (int a[], int k, int c[], int *ncandidates)
{
    bool bools[MAX + 1];

    if (k == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            c[*ncandidates] = i;
            *ncandidates += 1;
        }
    }

    for (int i = 0; i <= n; i++) bools[i] = true;
    for (int i = 0; i < k; i++) bools[a[i]] = false;

    for (int i = 1; i <= n; i++)
    {
        if (bools[i] == true && i > a[k - 1])
        {
            c[*ncandidates] = i;
            *ncandidates += 1;
        }
    }

}

void backtrack (int a[], int k)
{
    int c[MAX];
    int ncandidates = 0;

    if (k == n + 1) return;

    printf ("{ ");
    for (int i = 0; i < k; i++) printf ("%d ", a[i]);
    printf ("}\n");

    construct_candidates (a, k, c, &ncandidates);

    k++;

    for (int i = 0; i < ncandidates; i++)
    {
        a[k - 1] = c[i];
        backtrack (a, k); 
    }
}

int main ()
{
    int a[MAX];
    n = 4;

    backtrack (a, 0);

    return 0;
}