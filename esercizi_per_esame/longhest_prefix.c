#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
typedef char Str[MAX];

Str m[MAX];

void longhest_prefix (Str strings[MAX], int n, char prefix[])
{
    char c;
    bool end = false;
    
    int i, j = 0;
    while (! end && strings[0][j] != '\0')
    {
        i = 0;
        c = strings[i][j];

        while (i < n && strings[i][j] == c)
        {
            i++;
        }
        if (i < n) end = true;
        else prefix[j] = c;
        
        j++;
    }
    prefix[j] = '\0';
}

int main ()
{

    Str strings[MAX];
    int n = 0;

    char prefix[MAX];

    strcpy (strings[0], "loop");
    strcpy (strings[1], "loop");
    strcpy (strings[2], "loop");
    strcpy (strings[3], "loos");

    longhest_prefix (strings, 4, prefix);
    printf ("%s\n", prefix);

    return 0;
}