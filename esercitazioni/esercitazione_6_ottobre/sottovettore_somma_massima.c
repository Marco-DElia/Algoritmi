#include <stdlib.h>
#include <stdio.h>

// 3, 5, 8, -1, -7, 8, -6, 1

int max_subv (int *v, int n)
{
    int current_sum = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum += v[i];

        if (current_sum > sum)
        {
            sum = current_sum;
        }
        if (current_sum < 0)
            current_sum = 0;
    }
    return sum;
}


int T (int i, int j)
{
    if(i == 1 || j == 1 || j == i + 1) return 1;
    
    else return T (i - 1, j - 1) + T (i - 1, j);
      
}

void vcopy (int *vc, int *v, int n)
{
    for (int i = 0; i < n; i++) 

        vc[i] = v[i];
}

int TV (int *v, int i)
{
    int *vc = NULL;
    int olddim = i;
    int newdim = i + 1;

    if (i == 0)
    {
        v[0] = 1;
    }
    else if (i == 1)
    {
        v[0] = 1;
        v[1] = 2;
        v[2] = 1;
    }
    else
    {
        TV(v, i - 1);

        vc = malloc (sizeof(int) * olddim);
        vcopy (vc, v, olddim);

        for(int j = 0; j < newdim; j++)
        {
            if (j == 0 || j == newdim - 1) v[j] = 1;

            else v[j] = vc[j - 1] + vc[j];

        }
        free(vc);
    }

    return newdim;
}

int main ()
{
    /*
    int v[] = {-1, 2, -4, 2, 4, -1, -1, 3, -6, 7};


    printf("%d", max_subv (v, 10));
    */
    //printf ("%d", T(4, 5));

    int vector[100];

    int i = 4;
    
    int dim = TV(vector, i);

    for(int j = 0; j < dim; j++)

        printf("%d", vector[i]);

    printf("\n");

    return 0;
}
