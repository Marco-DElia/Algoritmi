#include <stdio.h>
#define max_size 20

void vprint (int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void vcpy (int d[], int v[], int n)
{
    for (int i = 0; i < n; i++)
        d[i] = v[i];
}

int join (int v[], int l, int m, int r)
{
    int nswap = 0;
    int vl[max_size];
    int vr[max_size];

    vcpy (vl, v + l, m - l + 1);
    vcpy (vr, v + m + 1, r - m);

    int i = 0, j = 0;
    while (i < m - l + 1 && j < r - m)
    {
        if (vl[i] <= vr[j])
        {
            v[l + i + j] = vl[i];
            i++;
        }
        else if (vr[j] < vl[i])
        {
            v[l + i + j] = vr[j];
            nswap += m - l + 1 - i;
            printf ("NSWAAP: %d\n", nswap);

            j++;
        }
    }
    while (i < m - l + 1)
    {
        v[l + i + j] = vl[i];
        i++;
    }
    while (j < r - m)
    {
        v[l + i + j] = vr[j];
        nswap += m - l + 1 - i;

        j++;
    }
    return nswap;
}

int merge_sort (int v[], int l, int r)
{
    int nswap = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        nswap += merge_sort (v, l, m);
        vprint (v, m - l + 1);
        
        nswap += merge_sort (v, m + 1, r);
        vprint (v, r - m);

        nswap += join (v, l, m, r);
    }
    printf ("%d\n", nswap);
    return nswap;
}


int main ()
{
    int vector[] = {4, 5, 2, 5, 1, 7};

    int nswap = merge_sort (vector, 0, 5);

    for (int i = 0; i < 6; i++)
        printf ("%d ", vector[i]);

    printf ("\n%d\n", nswap);
}