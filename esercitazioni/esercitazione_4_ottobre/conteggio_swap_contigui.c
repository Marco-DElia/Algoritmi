#include <stdio.h>
#include <stdlib.h>

int sort (int *vector, int n)
{
    int n_swap = 0;
    
    for(int i = 0; i < n; i++)
    {    
        for(int j = 1; j < n - i; j++)
        {    
            if(vector[j - 1] > vector[j])
            {    
                int temp = vector[j - 1];
                vector[j - 1] = vector[j];
                vector[j] = temp;

                n_swap++;
            }
        }
    }
    return n_swap;
}

void vprint (int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void vcopy (int *v1, int *v2, int n)
{
    for(int i = 0; i < n; i++)
    {
        v1[i] = v2[i];
    }
}

int merge (int *v, int l, int m, int r)
{
    /*
    Devo copiare le informazioni del vettore di partenza in due sottovettori:
    - copio v da l ad m, copio v da m+1 ad r
    - confronto la testa dei due vettori, la maggiore passa in v
    
    */
    int counter = 0;

    int *vl;
    int *vr;
    int vl_n = m - l + 1;
    int vr_n = r - m;

    {
        vl = malloc (sizeof(int) * vl_n);
        vr = malloc (sizeof(int) * vr_n);

        if (vl == NULL || vr == NULL)
        {
            perror ("malloc failed");
            return -1;
        }

        vcopy (vl, v + l    , vl_n);
        vcopy (vr, v + m + 1, vr_n);
    }

    {
        int i = vl_n - 1, j = vr_n - 1, k = r;

        while (i >= 0 && j >= 0)
        {
            if (vl[i] > vr[j])
            {
                v[k] = vl[i];
                k--;
                i--;

                counter += j + 1;
            }

            if (vl[i] < vr[j])
            {
                v[k] = vr[j];
                k--;
                j--;
            }

            if (vl[i] == vr[j])
            {
                v[k] = vl[i];
                k--;
                i--;
                j--;
            }
        }

        while (i >= 0) //significa che ci sono numeri ancora da copiare
        {
            v[k] = vl[i];
            //counter += i;
            k--;
            i--;
        }
        while (j >= 0)
        {
            v[k] = vr[j];
            //counter += j;
            k--;
            j--;

        }
    }

    //printf("Stampo vettore: \n");
    //vprint(v, r - l + 1);

    free (vl);
    free (vr);

    return counter;
}

int merge_sort (int *v, int l, int r)
{
    int m;
    int counter = 0;

    if (l < r)
    {
        m = (l + r) / 2;

        counter += merge_sort (v, l, m);
        counter += merge_sort (v, m + 1, r);
        counter += merge (v, l, m, r);
        
    }

    return counter;
}

#define _NORMAL_
#ifdef _NORMAL_

int main(void)
{
	// your code goes here
	
	int v11[]  = {9, 1, 0, 5, 4};
	int v12[]  = {9, 1, 0, 5, 4};

	int v21[] = {1, 2, 3};
	int v22[] = {1, 2, 3};

    int v31[] = {100, 30, 22, 9, 7, 6, 4, 3, 2, 1};
    int v32[] = {100, 30, 22, 9, 7, 6, 4, 3, 2, 1};

    int v41[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int v42[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int *M[] = {v11, v12, v21, v22, v31, v32, v41, v42};
    int dims[] = {5, 4, 3, 2, 10, 9, 8, 7};


    int n_bubble, n_merge_sort;


    for (int i = 0; i < 8; i+=2)
    {
        n_bubble = sort (M[i], dims[i]);
        n_merge_sort = merge_sort (M[i + 1], 0, dims[i + 1]);

        printf("n_bubble: %d, n_merge_sort: %d, difference: %d\n", n_bubble, n_merge_sort, n_bubble - n_merge_sort);
    }

	
	return 0;
}

#else

int main() 
{
    //Uso questo main per provare la funzione merge

    int v[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int v1[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};

    printf ("swaps: %d\n", merge (v1, 0, 4, 8));
    printf ("swaps bubble: %d\n", sort (v, 9));

    //vprint(v, 9);


    return 0;
}

#endif
