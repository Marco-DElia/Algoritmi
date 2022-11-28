#include <stdio.h>
#include <stdbool.h>

#define MAX 16
int n;

bool is_prime (int n)
{
    bool is_prime = true;
    
    int i = 2;
    while (i < n && is_prime)
    {
        if (n % i == 0)

            is_prime = false;

        i++;
    }
    return is_prime;
}

bool is_solution (int k)
{
    return k == n;
}

void elaborate_solution (int a[], int k)
{
    int i = 0;
    bool prime = true;
    while (i < k && prime)
    {
        if (i <= k - 2)
        {
            if (is_prime (a[i] + a[i + 1]) == false)
                prime = false;
        }
        else
        {
            if (is_prime (a[0] + a[i]) == false)
                prime = false;
        }
        i++;
    }
   
    if (prime) 
    {
        for (int i = 0; i < k; i++)
        {
            printf ("%d ", a[i]);
        }
        printf ("\n");
    }
}

void construct_candidates (int a[], int k, int c[], int *ncandidates)
{
    bool bools[MAX];

    if (k == 0)
    {
        c[0] = 1;
        *ncandidates = 1;
        return;
    }

    /*for (int i = 0; i < k; i++)
    {
        printf ("%d ", a[i]);
    }
    printf ("\n");*/

    for (int i = 0; i < n; i++) bools[i] = true;
    for (int i = 0; i < k; i++) bools[a[i] - 1] = false;

    //printf ("ciao\n");

    for (int i = 0; i < n; i++)
    {
        if (bools[i] == true)
        {
            c[*ncandidates] = i + 1;
            *ncandidates += 1;
        }
    }
    //printf ("joo\n");
}

void backtrack (int a[], int k)
{
    int c[MAX];
    int ncandidates = 0;

    if (is_solution (k))
    {
        elaborate_solution (a, k);
    }
    else
    {
        construct_candidates (a, k, c, &ncandidates);

        /*for (int i = 0; i < ncandidates; i++)
        {
            printf ("%d ", c[i]);
        }*/

        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];

            backtrack (a, k + 1);
        }
    }
}

void solve ()
{
    int a[MAX];
    int k = 0;

    backtrack (a, k);
}


int main ()
{
    char buffer[8];
    while (fgets (buffer, 7, stdin) && buffer[0] != '\n')
    {
        sscanf (buffer, "%d", &n);
        solve ();
        printf ("\n");
    }
    

    return 0;
}