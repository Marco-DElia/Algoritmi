#include <stdio.h>
#include <stdbool.h>

bool inline cond (int c, int x)
{
    return c >= x*(x+1)/2  && c < (x+1)*(x+2)/2;
}


// Solve the problem in O(logn)
int solve (int c)
{
    //log search
    float x = c/2 + 1;
    while (!cond (c, x))
    {
        if (c < x*(x+1)/2)
        {
            x = x/2;
        }
        else
        {
            x += x/2;
        }
    }
    
    return x;
}

int main(void) {
	// your code goes here
	int T, c;
	
	scanf ("%d", &T);
	while (T--)
	{
	    scanf ("%d", &c);
	    printf ("%d\n", solve (c));
	}
	
	return 0;
}


