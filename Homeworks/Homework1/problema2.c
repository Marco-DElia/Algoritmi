/*
***************************PROBLEMA-2 HOMEWORK-1*******************
                        EMANUELE D'AJELLO - MARCO D'ELIA

    Soluzione:
                - Struttura Dati (Vettore associativo: corrispondenza tra gli elementi del vettore (valore) e la loro posizione (chiave))
                  per non perdere il riferimento alla posizione dopo l'ordinamento.

                - Ordinamento con Merge Sort, in base al valore, in O(nlogn) della nuova Struttura Dati, cosicche' la posizione degli elementi
                  ordinati equivalga al numero di elementi minori o uguali (anche di se stesso) presenti (al netto degli elementi uguali,
                  caso che viene gestito con un conteggio).

                - L'output finale (vettore che in posizione i ha il numero di elementi minori o uguali dell'elementi i-esimo del vettore originario) e' ottenuto
                  scorrendo dalla fine il vettore associativo, e utilizzando l'indice (chiave) memorizzato nella posizione considerata, per accedere
                  direttamente alla posizione corretta nel vettore di output. In questa posizione verra' scritto il numero di elementi minori
                  (indice del ciclo di scorrimento) piu' un opportuno conteggio in caso di elementi uguali.
*/

#include <stdio.h>
#include <stdlib.h>

// Struttura di associazione (Joint - Giunzione) indice-valore.
struct Joint
{
    int value;
    int index;
};

// Costruzione di un vettore associativo a partire da un vettore di interi.
// Complessita': O(n)
struct Joint* build_joints (int *v, int n)
{
    struct Joint *joints = malloc (sizeof(struct Joint) * n);

    if (joints == NULL)
    {
        printf ("Error in build joints (Malloc failed !)\n");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        joints[i].value = v[i];
        joints[i].index = i;
    }

    return joints;
}


void print_joints (struct Joint *joints, int n)
{
    
    for (int i = 0; i < n; i++)
    {
        printf ("[%d, %d]  ", joints[i].value, joints[i].index);
    }
    printf ("\n");
}


void free_joints (struct Joint *joints)
{
    free(joints);
}

// Costruzione di un vettore associativo a partire da un'altro (copia).
// Complessita': O(n)
struct Joint * build_joints_frJ (struct Joint* joints, int n)
{
    struct Joint *j = malloc (sizeof(struct Joint) * n);

    if (j == NULL)
    {
        printf ("Error in built_joints_frJ (Malloc failed)\n");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        j[i].value = joints[i].value;
        j[i].index = joints[i].index;
    }

    return j;
}

// Passo di combine dell'algoritmo di ordinamento Merge Sort.
// Complessita': O(n)
void combine (struct Joint *joints, int l, int q, int r)
{
    int il = 0, ir = 0;
    int nl = q - l + 1, nr = r - (q + 1) + 1;

    struct Joint *jl = build_joints_frJ (joints + l, nl);
    struct Joint *jr = build_joints_frJ (joints + q + 1, nr);


    while (il < nl && ir < nr)
    {
        if (jl[il].value <= jr[ir].value)
        {
            joints[l + il + ir].value = jl[il].value;
            joints[l + il + ir].index = jl[il].index;

            il++;
        }
        else
        {
            joints[l + il + ir].value = jr[ir].value;
            joints[l + il + ir].index = jr[ir].index;

            ir++;
        }
    }

    while (il < nl)
    {
        joints[l + il + ir].value = jl[il].value;
        joints[l + il + ir].index = jl[il].index;

        il++;
    }

    while (ir < nr)
    {
        joints[l + il + ir].value = jr[ir].value;
        joints[l + il + ir].index = jr[ir].index;

        ir++;        
    }

    free_joints (jl);
    free_joints (jr);
}

// Merge sort.
// Complessita': O(nlogn)
void merge_sort (struct Joint *j, int l, int r)
{
    if (l != r)
    {
        int q = (l + r) / 2;

        merge_sort (j, l, q);
        merge_sort (j, q + 1, r);
        combine (j, l, q, r);
    }
}


// Creazione del vettore di output a partire da un input (vettore di interi).
// Complessita': O(n)
int * solve (int *input, int n)
{
    // Caso di vettore di input vuoto
    if (n == 0) return NULL;

    struct Joint *j = build_joints (input, n);

    // Ordinamento del vettore associativo
    merge_sort (j, 0, n - 1);

    int *output = malloc (sizeof(int) * n);

    if (output == NULL)
    {
        printf ("Error in solve (Malloc failed !)\n");
        return NULL;
    }

    // Popolazione del vettore di output scorrendo dalla fine il vettore
    // associativo ordinato.
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        //conteggio in caso di elementi successivi uguali
        if (i < n - 1 && j[i].value == j[i + 1].value)  
            count++;
        else
            count = 0;

        // Accesso diretto al vettore di output tramite le posizioni
        // conservate nel vettore associativo.
        // In questa posizione viene salvato l'indice del ciclo piu'
        // il conteggio.
        // Nota: il conteggio serve per fornire un numero di elementi
        // minori uguali, utilizzando l'indice del ciclo. Infatti
        // si nota che, in caso di elementi uguali, il contatore
        // aumenta e l'indice decrementa, quindi la somma e' costante.
        // Nota: Il '+ 1' e' per il conteggio dell'elemento stesso, che e'
        // minore o uguale di se stesso.
        output[j[i].index] = i + 1 + count;
    }

    free_joints (j);

    return output;
}

void Test (int *input, int n)
{
    // Stampa del vettore sotto test
    printf ("Vettore di input:\n");

    for (int i = 0; i < n; i++)
    {
        printf ("%d ", input[i]);
    }
    printf ("\n");

    // Risoluzione
    int *s = solve (input, n);

    if (s != NULL)
    {
        // Stampa del vettore di output
        printf ("Vettore di output:\n");
        for (int i = 0; i < n; i++)
        {
            printf ("%d ", s[i]);
        }
        printf ("\n\n");

        free (s);
    }
    else
    {
        printf ("Vettore vuoto.\n\n");
    }
}


int main ()
{

    // TEST 1
    // Vettore di elementi non tutti uguali
    // Vettore di input: [7, 2, 3, 1, 5, 0, 5, 7, 4]
    // Risultato atteso: [9, 3, 4, 2, 7, 1, 7, 9, 5]

    int input1[] = {7, 2, 3, 1, 5, 0, 5, 7, 4};
    int n1 = 9;

    printf ("Caso Test 1\n");
    Test (input1, n1);

    // TEST 2
    // Vettore di tutti elementi uguali
    // Vettore di input: [7, 7, 7, 7, 7, 7, 7, 7, 7]
    // Risultato atteso: [9, 9, 9, 9, 9, 9, 9, 9, 9]
  
    int input2[] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
    int n2 = 9;

    printf ("Caso Test 2\n");
    Test (input2, n2);

    // TEST 3
    // Vettore con gruppi di elementi uguali
    // Vettore di input: [5, 5, 10, 10, 10]
    // Risultato atteso: [2, 2, 5, 5, 5]
    int input3[] = {5, 5, 10, 10, 10};
    int n3 = 5;

    printf ("Caso Test 3\n");
    Test (input3, n3);

    // TEST 4
    // Vettore vuoto
    // Vettore di input: []
    // Risultato atteso: "Vettore vuoto"
    int input4[] = {};
    int n4 = 0;

    printf ("Caso Test 4\n");
    Test (input3, n4);
    

    return 0;
}