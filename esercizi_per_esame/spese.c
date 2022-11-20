#include <stdio.h>
#include <math.h>

float solve (float input[], int s)
{
    float mean = 0, result = 0;
    for (int i = 0; i < s; i++) mean += input[i];

    mean = mean / s;
    mean = floorf ((mean + 0.005) * 100) / 100;

    for (int i = 0; i < s; i++)
    {
        if (input[i] > mean) result += input[i] - mean;
    }

    return result;
}

int main ()
{
    float input[1000] = {15.00, 15.01, 3.00, 3.01};
    int s = 4;
 
    scanf ("%d", &s);

    while (s)
    {
        for (int i = 0; i < s; i++)

            scanf ("%f", &input[i]);

        printf ("%.2f\n", solve (input, s));

        scanf ("%d", &s);
    }


    return 0;
}