#include <stdio.h>
#include <math.h>

#define DIM 100
int vector[DIM];
int vectorL[DIM];
int vectorR[DIM];

int ndiv (int x, int y)
{
    //assumo y pari
    int n = 1;

    if (x < y || y == 1) return x;

    while (x != 1)
    {

        x = x / y;
        n++;
    }
    return n;
}

void Solve (int d, int depth, int i, int *sum)
{
    if (d == depth)
    
        return;
    
    if (ndiv (i, (int) pow (2, d - 1)) % 2 != 0 )
    {
        printf ("ndivs DISPari : %d, sum: %d\n", ndiv (i, (int) pow (2, d - 1)),*sum);
        *sum *= 2;
    }
    else
    {
        printf ("ndivs Pari : %d, sum: %d\n", ndiv (i, (int) pow (2, d - 1)),*sum);

        *sum *= 2;
        (*sum)++;
    }
    Solve (d + 1, depth, i, sum);
}


void vsplit (int *v, int n, int *l, int *nl, int *r, int *nr)
{
    *nl = 0;
    *nr = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            l[*nl] = v[i - 1];
            *nl += 1;
        }
        else
        {
            r[*nr] = v[i - 1];
            *nr += 1;
        }
    }
}

// Da sostituire con ricerca binaria
int vsearch (int *v, int n, int e)
{
    int find = 0;
    int i = 0;

    while (! find && i < n)
    {
        if (v[i] == e)

            find = 1;

        i++;
    }
    return find;
}

void vpop (int *v, int n)
{
    for (int i = 1; i <= n; i++)

        v[i - 1] = i;
}

void vprint (int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf ("%d, ", v[i]);
    }
    printf ("\n");
}

int solve1 (int depth, int i)
{
    int d = 0, sum = 1;
    int n = i, nl, nr;
    int *v = vector, *vl = vectorL, *vr = vectorR;

    vpop (v, i);
    //vprint (v, i);
    
    while (d != depth - 1)
    {
        vsplit (v, n, vl, &nl, vr, &nr);
        //vprint (vl, nl);
        //vprint (vr, nr);
        printf ("sinistro:\n");
        vprint (vl, nl);

        printf ("destro:\n");
        vprint (vr, nr);

        if (vsearch (vr, nr, i) == 0)
        {
            //printf ("sinistro:\n");
            //vprint (vl, nl);

            sum *= 2;
            v = vectorL;
            n = nl;
            vl = vector;
        }
        else
        {
            //printf ("destro:\n");
            //vprint (vr, nr);
            sum *= 2;
            sum++;
            v = vectorR;
            n = nr;
            vr = vector;
        }

        d++;        
    }

    return sum;
}


int main ()
{
    /*  
    vpop (vector, 4);
    vprint (vector, 4);
    int nl, nr;
    vsplit (vector, 4, vectorL, &nl, vectorR, &nr);
    printf ("Sinistra\n");
    vprint (vectorL, nl);
    printf ("%d\n", nl);

    printf ("Destra\n");
    vprint (vectorR, nr);
    printf ("%d\n", nr);
    */


    printf ("sum: %d", solve1 (5, 14));
}