#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vmax (int *v, int n)
{
    int max = v[0];

    for (int i = 1; i < n; i++)
    {
        if (v[i] > max) max = v[i];
    }
    return max;
}

void vprint (int *v, int n)
{
    for (int i = 0; i < n; i++) printf ("%d ", v[i]);
    printf ("\n");
}

void quick_sort (int *v, int *vo, int n, int m)
{
    m++;

    int *vm = malloc (sizeof(int) * (m));

    if (!vm)
    {
        printf ("Error in quick_sort. Malloc failed.\n");
        return;
    }

    //setup
    for (int i = 0; i < m; i++) vm[i] = 0;
    for (int i = 0; i < n; i++) vm[v[i]] += 1;
    for (int i = 1; i < m; i++) vm[i] += vm[i - 1];

    //place
    for (int i = n - 1; i >= 0; i--)
    {
        vo[vm[v[i]] - 1] = v[i];
        vm[v[i]] -= 1;
    }

    free (vm);
}

int vfind (int *v, int n, int e)
{
    int find = 0, i = 0;

    while (! find && i < n)
    {
        if (v[i] == e) find = 1;

        i++;
    }

    return find == 1 ? --i : -1;
}


int main ()
{
    int v[10] = {2, 3, 5, 1};
    int o[10] = {};
    int n = 4;
    int m = vmax (v, n);

    quick_sort (v, o, n, m);
    int query = 5;
    printf ("Trovato %d, in posizione %d\n", query, vfind (o, n, query));

    return 0;
}