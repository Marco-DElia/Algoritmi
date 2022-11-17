#include <stdio.h>

typedef struct
{
    int w, qi;
    int index;

} Elephant;

Elephant vector [100];
int n = 6;

int output[100];
int k = 0;

void Elecpy (Elephant *d, Elephant *s)
{
    d->qi = s->qi;
    d->index = s->index;
    d->w = s->w;
}

void insertion_sort() {

    for(int i = 1; i < n; i++) {

        int j = i;
        Elephant e;

        while(vector[j].w <= vector[j-1].w && j > 0){
            
            if (vector[j].w == vector[j-1].w)
            {
                if (vector[j].qi < vector[j-1].qi)
                {
                    Elecpy (&e, &vector[j]);
                    Elecpy (&vector[j], &vector[j - 1]);
                    Elecpy (&vector[j - 1], &e);
                }
            }
            else
            {
                Elecpy (&e, &vector[j]);
                Elecpy (&vector[j], &vector[j - 1]);
                Elecpy (&vector[j - 1], &e);
            }

            j--;
        }
    }
}

void Eprint ()
{
    for (int i = 0; i < n; i++)
    {
        printf ("(%d, %d, %d), ", vector[i].w, vector[i].qi, vector[i].index);
    }
    printf ("\n");
}

void calc ()
{
    int max_j = -1, max_i = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        j = 0;
        while (i + j < n - 1 && vector[i + j].qi > vector[i + j + 1].qi)
        {
            j++;
        }
        if (j > max_j)
        {   max_i = i;
            max_j = j;
        }

        i += j + 1;
    }

    for (int q = 0; q <= max_j; q++)
    {
        output[q] = vector[q + max_i].index;
    }
    k = max_i + max_j;
}


int main ()
{
    /*
    vector[0].w = 1;
    vector[0].qi = 5;
    vector[0].index = 0;

    vector[1].w = 3;
    vector[1].qi = 4;
    vector[1].index = 1;

    vector[2].w = 2;
    vector[2].qi = 9;
    vector[2].index = 2;

    vector[3].w = 4;
    vector[3].qi = 2;
    vector[3].index = 3;

    vector[4].w = 5;
    vector[4].qi = 1;
    vector[4].index = 4;

    vector[5].w = 10;
    vector[5].qi = 10;
    vector[5].index = 5;
    */

    int w, qi;
    n = 0;

    while (scanf (" %d %d", &w, &qi) == 2)
    {
        vector[n].w = w; 
        vector[n].qi = qi; 
        vector[n].index = n;

        n++; 
    }
    //n++;

    Eprint ();
    insertion_sort ();
    Eprint ();

    calc ();

    printf ("%d\n", k);

    for (int i = 0; i < k; i++)
    {
        printf ("%d\n", output[i] + 1);
    }
    printf ("\n");

    return 0;
}