#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Scrivo una funzione che, data una stringa A ed una B, cerca A (a partire dalla fine - inversa) in B
// Esempio: A = "abcde", B = "mrcedcfta" => TROVATA
// A = string[:i], B = [i+1:]
bool find (char *string, int i) 
{
    bool find = false;

    for (int j = i; j >= 0; j--)
    {
        find = false;
        for (int k = i + 1; string[k] != '\0'; k++)
        {
            if (string[j] == string[k]) 
                find = true;
        }
        if (!find) j = -1;
    }
    return find;
}


bool findv2 (char *A, char *B)
{
    size_t jp = -1;
    bool find = true;

    for (size_t i = 0; A[i] != '\0' && find; i++)
    {
        find = false;
        for (size_t j = jp + 1; B[j] != '\0' && !find; j++)
        {
            if (A[i] == B[j])
            {
                printf ("i = %d, j = %d\n", i, j);
                jp = j;
                find = true;
            }
        }
    }
    return find;
}

int max_pal (char *string, int l, char *A, int nA)
{
    // Senza Memoization
    int max = 0;
    int dimA = 0;

    if (string[l] != '\0')
    {

        

        // Non metto la lettera
        int n1 = max_pal (string, l + 1, A, nA);
 
        // Metto la lettera
        A[nA] = string[l];
        int n2 = max_pal (string, l + 1, A, nA + 1);

        max = (n1 > n2 ? n1 : n2);
        // Devo lavorare su di una copia di A, per farne poi il REVERSE
        if (findv2 (A, string + l)) // Interire il controllo della dimensione di A
        {
            dimA = nA;
            // Se non lo trova, allora non dovrei controllare tutte le stringhe che finiscono con la
            // lettera in nA-1
        }

        return (dimA > max ? dimA : max);
    }
}

int main ()
{
    char s[] = "cdhuhuhuuhu";
    char s2[] = "";

    printf ("%d", findv2 (s, s2));

}



