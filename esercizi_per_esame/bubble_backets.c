#include <stdio.h>

int bubble_sort (int vector[], int n)
{
    int nsorts = 0;
    int j, i;
    int temp;

    for (i = 0; i < n - 1; i++)
    {
        j = 0;
        while (j < (n - i - 1))
        {
            if (vector[j] > vector[j + 1])
            {
                nsorts++;
                temp = vector[j + 1];
                vector[j + 1] = vector[j];
                vector[j] = temp;
            }
            j++;
        }
    }
    
    return nsorts;
}

void solve (int vector[], int n)
{
    int nsorts = bubble_sort (vector, n);

    if (nsorts % 2 == 0)
    {
        printf ("Vince Carlos\n\n");
    }
    else
    {
        printf ("Vince Marcelo\n\n");
    }

}

int main ()
{
    int vector[100];
    int n = 0;

    do
    {
        scanf ("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d",  &vector[i]);
        }

        if (n != 0)
            solve (vector, n);

    } while (n != 0);
    

    return 0;
}