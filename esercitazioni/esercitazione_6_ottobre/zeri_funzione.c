#include <stdio.h>
#include <stdlib.h>

int expn (int b, int e)
{
    if (e == 0)
        return 1;

    int r = b;

    for (int i = 0; i < e - 1; i++)

        r *= b;

    return r;
}

int string2int (char *s, int n)
{
    int i = 0, result = 0;

    if (s[0] == '-')
    {
        n--;
        i++;
    }

    for (int k = n + i - 1; k >= i; k--)

        result += (s[k] - '0') * expn (10, n - k - 1 + i);

    if (s[0] == '-')
        result *= -1;

    return result;
}
/*
int read_input (char *input, int **result, int *dims)
{
    int n = 0;

    {
        int i = 0;

        while (input[i] != 'E')
        {
            if (input[i] != '\n' && input[i] != ' ')
            {
                n++;
            }
            i++;
        }
        // Ho ottenuto la pura dimensione dell'input
    }

    result = malloc (sizeof(int) * n);

    if(result == NULL)
    {
        printf ("MALLOC FAILED !\n");
        return -1;
    }

    {
        char token[10];
        int i = 0, t = 0, sub_n = 0;

        while (input[i] != 'E')
        {
            while (input[i] != 'E' || input != '\n')
            {
                token[t] = input[i];
                t++;
                i++;
            }
        }
    }
}

*/
int main ()
{
    char input[] = "0 0 0 0 -2 1\n1 0 0 0 -1 2\nEND";

    return 0;
}