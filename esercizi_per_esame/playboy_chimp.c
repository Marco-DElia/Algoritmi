#include <stdio.h>


void solve (int input[], int n, int height, int output[2])
{
    int point = n/2;
    int prev_point;
    int var = 1;

    while (var && point < n)
    {
        prev_point = point;

        if (height > input[point])
        {
            point += point/2;
            var = point - prev_point;
        }
        if (height < input[point])
        {
            point -= point/2;
            var = prev_point - point;
        }
        if (height == input[point])

            var = 0;
    }
    printf ("point: %d\n", point);

    if (point == 0)
    {
        output[0] = input[0];
        output[1] = -1;

    }
    else if (point == n - 1)
    {
        output[0] = input[point];
        output[1] = -1;
    }
    else if (input[point] == height)
    {
        output[0] = input[point - 1];
        output[1] = input[point + 1];
    }
    else
    {
        output[0] = input[point];
        output[1] = input[point + 1];
    }
}

int binary (int input[], int n, int e)
{
    int l = 0;
    int r = n - 1;
    int m;

    while (r >= l)
    {
        m = (l + r) / 2;

        if (e == input[m])
        {
            return m;
        }
        if (e < input[m])
        {
            r = m - 1;
        }
        if (e > input[m])
        {
            l = m + 1;
        }
    }
    
    if (r < l) return -1;
}

int mod_binary (int input[], int n, int e)
{
    int l = 0;
    int r = n - 1;
    int m;
    int old_m;

    while (r >= l)
    {
        m = (l + r) / 2;
        old_m = m;
        if (e == input[m])
        {
            return m;
        }
        if (e < input[m])
        {
            r = m - 1;
        }
        if (e > input[m])
        {
            l = m + 1;
        }
    }
    
    if (r < l) return old_m;
}

void mod_solve (int input[], int n, int h, int output[2])
{
    int m = mod_binary (input, n, h);
    printf ("M: %d\n", m);
    if (input[m] == h)
    {
        //find
        if (n == 1)
        {
            output[0] = -1;
            output[1] = -1;
        }
        if (m == n - 1)
        {
            output[0] = input[m - 1];
            output[1] = -1;
        }
        else if (m == 0)
        {
            output[0] = input[m + 1];
            output[1] = -1;
        }
        else
        {
            output[0] = input[m - 1];
            output[1] = input[m + 1];
        }
        
    }
    else
    {
        //not find
        if (n == 1)
        {
            output[0] = input[0];
            output[1] = -1;
        }
        if (m + 1 == n - 1)
        {
            output[0] = input[m - 1];
            output[1] = input[m];
        }
        else if (m == 0)
        {
            output[0] = input[m];
            output[1] = -1;
        }
        else
        {
            output[0] = input[m];
            output[1] = input[m + 1];
        }
        
    }
}


int main ()
{

    int input[6] = {2, 4, 5, 7};
    int output[2];

    mod_solve (input, 4, 1, output);
    printf ("%d, %d\n", output[0], output[1]);
    //printf ("bin: %d\n", mod_binary (input, 4, 8));
}