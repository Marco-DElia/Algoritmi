#include <stdio.h>
#include <stdbool.h>

bool possible_draw (int A, int B, int C)
{
    if (A == B + C) return true;
    if (A + B == C) return true;
    if (A + C == B) return true;
    
    return false;
}


int main(void) {
	// your code goes here
	int A, B, C;
	int T;
	
	scanf ("%d", &T);
	while (T--)
	{
	    scanf ("%d %d %d", &A, &B, &C);
	    printf ("%d\n", possible_draw (A, B, C));
	}
	
	return 0;
}

