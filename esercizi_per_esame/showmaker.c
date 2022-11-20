#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int time, fine;
} Job;

#define MAX 10

Job input[MAX];
int n;

int output[MAX];
int o;

int min_cost = 100000;

bool is_solution (int k)
{
    return k == n;
}

void compute_solution (int a[])
{
    printf ("permut:\n");
    for (int i = 0; i < n; i++)
    {
        printf ("%d ", a[i]);
    }
    printf ("\n");
    

    int cost = 0;
    int time = input[a[0]].time;

    for (int i = 1; i < n; i++)
    {
        cost += input[a[i]].fine * (time);

        time += input[a[i]].time;
    }

    if (cost < min_cost) 
    {
        min_cost = cost;

        //printf ("SOLUTION:\n");

        for (int i = 0; i < n; i++)
        {
            output[i] = a[i];
            //printf ("%d ", a[i]);
        }
        //printf ("\n");
    }
}

void construct_candidates (int a[], int k, int c[], int *ncandidates)
{
    bool bools[MAX];

    for (int i = 0; i < n; i++) bools[i] = true;
    for (int i = 0; i < k; i++) bools[a[i]] = false;

    for (int i = 0; i < n; i++)
    {
        if (bools[i] == true)
        {
            c[*ncandidates] = i;
            *ncandidates += 1;
        }
    }
}


void backtrack (int a[], int k)
{
    int c[MAX];
    int ncandidates = 0;

    if (is_solution (k))
    {
        compute_solution (a);
    }
    else
    {
        construct_candidates (a, k, c, &ncandidates);
        k++;

        for (int i = 0; i < ncandidates; i++)
        {
            a[k - 1] = c[i];
            backtrack (a, k);
        }
    }
}

int main ()
{
    input[0].time = 3;
    input[0].fine = 4;

    input[1].time = 1;
    input[1].fine = 1000;

    input[2].time = 2;
    input[2].fine = 2;

    input[3].time = 5;
    input[3].fine = 5;

    n = 4;
    o = n;

    int a[MAX];
    int k = 0;

    backtrack (a, k);

    printf ("SOLUZIONE: \n");

    for (int i = 0; i < n; i++)
    {
        printf ("%d ", output[i] + 1);
    }
    printf ("\n");


    return 0;
}