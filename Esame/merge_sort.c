#include <stdio.h>
#include <stdlib.h>

void vprint (int *v, int n)
{
    for (int i = 0; i < n; i++)

        printf ("%d ", v[i]);

    printf ("\n");
}


void counting_sort (int *input, int *output, int n, int max)
{
    int nvs = max + 1;
    int * vsum = malloc (sizeof(int) * nvs);

    if ( vsum == NULL)
    {
        printf ("Error in couting_sort.\n");
        return;
    }

    for (int i = 0; i < nvs; i++)
    
        vsum[i] = 0;
   
    //vprint (vsum, nvs);

    
    for (int i = 0; i < n; i++)
    
        vsum[input[i]] += 1;

    //vprint (vsum, nvs);


    for (int i = 1; i < nvs; i++)

        vsum[i] = vsum[i - 1] + vsum[i];

    //vprint (vsum, nvs);

    for (int i = n - 1; i >= 0; i--)
    {
        output[vsum[input[i]] - 1] = input[i];
        vsum[input[i]]--;
    }
    free (vsum);
}


int main ()
{
    int v[] = {3, 2, 5, 1, 6, 8, 1, 0, 3, 5};
    int dim = 10;
    int max = 8;

    int o[10];

    counting_sort (v, o, dim, max);

    for (int i = 0; i < dim; i++)
    {
        printf ("%d ", o[i]);
    }

    return 0;
}