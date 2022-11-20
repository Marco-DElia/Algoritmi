#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 100

bool solve (int numbers[], int n)
{
    bool *bools = malloc (sizeof(bool) * n);
    
    for (int i = 0; i < n; i++) bools[i] = false;
    for (int i = 0; i < n - 1; i++)
    {
        int d = abs (numbers[i] - numbers[i + 1]);
     
        if (d == 0 || d > n - 1 || bools[d] == true) return false;
        bools[d] = true;
    }
    return true;
}

int main ()
{
    int numbers[5000];
    int n = 0;
    int T;
    
    scanf ("%d", &T);
    
    while (T--)
    {
        scanf ("%d", &n);
        int m = n;
        int k = 0;
        
       while (m--)
       {
           scanf ("%d", &numbers[k]);
           k++;
        }
        for (int i = 0; i < n; i++) printf ("%d", numbers[i]);
        printf ("%d", solve (numbers, n));
    }


    return 0;
}