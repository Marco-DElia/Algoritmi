#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void construct_candidates (int a[], int k, int n, int c[],  int *ncandidates)
{
    bool bools[MAX];

    for (int i = 0; i < n; i++) bools[i] = true;
    for (int i = 0; i < k; i++) bools[a[i]] = false;

    for (int i = 0; i < n; i++)
    {
        if (bools[i] == true)
        {
            c[*ncandidates] = i;
            *ncandidates += 1;
        }
    }
}

void backtrack (int a[], int k, int n)
{
    int c[MAX];
    int ncandidates = 0;

    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf ("%d ", a[i] + 1);
        }
        printf ("\n");
    }
    else
    {
        construct_candidates (a, k, n, c, &ncandidates);

        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];

            backtrack (a, k + 1, n);
        }

    }
}

int main ()
{
    int a[MAX];
    int n = 5;
    //backtrack (a, 0, n);

    char buff[8];

    while (1)
    {
        fgets (buff, 8, stdin);

        if (buff[0] == '\n') break;

        sscanf (buff, "%d", &n);

        backtrack (a, 0, n);
    }


    return 0;
}