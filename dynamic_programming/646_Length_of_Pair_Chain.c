#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Approccio DP

int solve (int** pairs, int pairsSize, int* pairsColSize, int index, int *memo)
{
    if (index == pairsSize - 1) return 1;

    if (memo[index] == 0)
    {
        int m1 = 0, m2 = 0, m = 0;
        for (int i = index + 1; i < pairsSize; i++)
        {
            if (pairs[index][1] < pairs[i][0])
                m1 = 1 + solve (pairs, pairsSize, pairsColSize, i, memo);
            
            m2 = solve (pairs, pairsSize, pairsColSize, i, memo);

            m = m > (m1 > m2 ? m1 : m2) ? m : (m1 > m2 ? m1 : m2);
            printf ("%d\n", m);
        }
        memo[index] = m;
    }
    else
        printf ("riuso\n");
        
    return memo[index];

}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){

    // Devo ordinare il vettore

    int *memo = malloc (sizeof (int) * pairsSize);
    memset (memo, 0, sizeof(int) * pairsSize);

    int m = solve (pairs, pairsSize, pairsColSize, 0, memo);

    free (memo);
    return m;
}

// Approccio Greedy (da controllare)
int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){

    // Devo ordinare il vettore

    int count = 1;

    for (int i = 1; i < pairsSize; i++)
    {
        if (pairs[i - 1][1] < pairs[i][0])
        {
            int j = i;
            while (j < pairsSize && pairs[i - 1][0] <= pairs[j][0] && pairs[i - 1][1] > pairs[j][1])
            {
                j++;
                i = j;
            }
            count += 1;
        }
    }
    return count + 1;
}

int main ()
{

    return 0;
}