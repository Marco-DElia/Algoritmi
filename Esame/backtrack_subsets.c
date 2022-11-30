#include <stdio.h>
#include <stdbool.h>


void backtrack (bool a[], int k, int n)
{
    bool c[2];

    c[0] = false;
    c[1] = true;
    int ncandidates = 2;

    if (k == n)
    {
        printf ("{");
        for (int i = 0; i < n; i++)
        {
            if (a[i] == true)
            {
                printf ("%d", i + 1);
            }
        }
        printf ("}\n");
    }
    else
    {
        //construct_candidates (c, &ncandidates);
        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            backtrack (a, k + 1, n);
        }
    }
}

int main ()
{
    bool a[10];
    int n;
    char buff[8];

    while (1)
    {
        fgets (buff, 8, stdin);
        
        if (buff[0] == '\n') break;

        sscanf (buff, "%d", &n);

        backtrack (a, 0, n);
        printf ("\n\n");
    }

    return 0;
}