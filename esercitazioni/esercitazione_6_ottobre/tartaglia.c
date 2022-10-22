#include <stdio.h>
#include <stdlib.h>

int tartaglia (int* buff, int row)
{
    // assumo che il buffer sia grande abbastanza e che row sia un numero non negativo

    // ritorno il valore di elementi

    int columns = row + 1;

    if (row == 1)
    {
        buff[0] = 1;
        return columns - 1;
    }

    if (row == 2)
    {
        buff[0] = 1;
        buff[1] = 2;
        buff[2] = 1;

        return columns;
    }

    int *vtemp = malloc (sizeof(int) * row);

    if (vtemp == NULL)
    {
        printf ("MALLOC FAILED !\n");
        return -1;
    }

    int old_columns = tartaglia (vtemp, row - 1);

    for (int i = 0; i < columns; i++)
    {
        if (i == 0 || i == columns - 1)
        
            buff[i] = 1;
        
        else

            buff[i] = vtemp[i - 1] + vtemp[i];
    }

    free(vtemp);

    return columns;
}

int main ()
{
    int buffer[100];

    for (int i = 1; i < 15; i++)
    {
        for (int j = 0; j < tartaglia (buffer, i); j++)
        {
            printf ("%d ", buffer[j]);
        }
            printf ("\n");

    }

    return 0;
}