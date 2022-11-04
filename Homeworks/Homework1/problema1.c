/*
***************************PROBLEMA-1 HOMEWORK-1*******************
                        EMANUELE D'AJELLO - MARCO D'ELIA

    Soluzione:
                - Linked List singolarmente linkata con insterimento in testa
                - Reverse della seconda metà della lista (di lunghezza 2n). Il reverse
                  è stato effettuato a partire dalla fine della lista, quindi una volta
                  attraversata tutta la lista, inizia la fase di reverse.

                  Schema esemplificativo della fese di reverse:

                  Lista:   1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888

                  Passo 1: 1111, 2222, 3333, 4444, 6666, 7777, 8888, 5555
                  Passo 2: 1111, 2222, 3333, 4444, 7777, 8888, 6666,5555
                  Passo 3: 1111, 2222, 3333, 4444, 8888, 7777, 6666, 5555

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_LENGTH 32


struct llNode
{
    struct llNode *next;
    char *data;
};

// Funzione di creazione nodo, si alloca la stringa da memorizzare
// immediatamente dopo la struttura.
struct llNode * create_node (char *string)
{
    struct llNode *node = malloc (sizeof(struct llNode) + strlen (string) + 1);

    if (node == NULL)
    {
        printf ("Error in create_node (malloc failed)\n");
        return NULL;
    }

    node->next = NULL;
    node->data = (char *) (node + 1);
    strcpy ((char *) (node + 1), string);

    return node;
}

// Si inserisce in testa, quindi l'inserimento è O(1).
void push_node (struct llNode **head, struct llNode *nnode)
{
    if(nnode == NULL) return;

    nnode->next = *head;
    *head = nnode;

}


void print_linked_list (struct llNode *head)
{
    struct llNode *temp = head;

     while (temp != NULL)
    {
        printf ("%s  ", temp->data);

        temp = temp->next;
    
    }

    printf ("\n");
}

void free_linked_list (struct llNode **head)
{
    struct llNode *temp = NULL;

    while (*head != NULL)
    {
        //print_linked_list (*head);

        temp = *head;
        *head = (*head)->next;
        free(temp);

    }
}

// Funzione di Reverse di una Linked List.
// IMPORTANTE: n è l'elemento della linked list dal quale
// effettuare il reverse. Nel caso richiesto dall'homework
// n è sempre la metà della lunghezza della linked list (che è pari).
// Questa procedura costa O(l) con l = lunghezza linked list.
void reversefn_linked_list (struct llNode **head, int n)
{
    struct llNode *last = *head, *first = NULL, *second = NULL;

    //setup
    // Dopo il setup, first punta al primo elemento da invertire (futura coda),
    // second al successivo di first e last all'elemento in coda.
    // Il setup ha costo O(l).
    {
        int i = 0;
        struct llNode *zero = NULL;
        while (last != NULL && last->next != NULL)
        {
            if (i == n - 1) zero = last;

            if (i == n)
            {
                first = last;
                second = last->next;
            }
            last = last->next;
            i++;
        }
        
        if (n == 0)

            *head = last;

        else if (zero != NULL)

            zero->next = last;

    }

    //reverse
    // Il reverse viene effettuato inserendo l'elemento first tra 
    // il last quello dopo il last. Poi vengono riaggiornati i
    // puntatori first e second.
    // Questa procedura di reverse ha un costo O(l).
    while (first != NULL && first != last)
    {
        first->next = last->next;
        last->next = first;
        first = second;
        second = second->next;
    }

}

void test (struct llNode *head, char input[][MAX_LENGTH], int dim)
{
    // Si assume che dim sia pari.

    for (int i = 0; i < dim; i++)
    
        push_node(&head, create_node (input[i]));
        
    
    printf ("Linked List inserita:\n");
    print_linked_list (head);

    reversefn_linked_list (&head, dim/2);

    printf ("Linked List invertita a metà:\n");
    print_linked_list (head);
    printf ("\n");

    free_linked_list (&head);
}




int main ()
{

    struct llNode *head = NULL;
    //La massima lunghezza di una stringa (solo per il test) è 32 bytes
    char vector [][MAX_LENGTH] = {"alfa", "beta", "gamma", "delta", "zeta", "eta", "theta", "iota", "kappa", "lambda"};
    int n = 10;
    printf ("TEST:\n");
    test (head, vector, n);


    char vector1 [][MAX_LENGTH] = {"8888", "7777", "6666", "5555", "4444", "3333", "2222", "1111"};
    int n1 = 8;
    printf ("TEST 1:\n");
    test (head, vector1, n1);


    char vector2 [][MAX_LENGTH] = {};
    int n2 = 0;
    printf ("TEST 2:\n");
    test (head, vector2, n2);


    char vector3 [][MAX_LENGTH] = {"2222", "1111"};
    int n3 = 2;
    printf ("TEST 3:\n");
    test (head, vector3, n3);
    

    return 0;
}