#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct llNode
{
    struct llNode *next;
    char *data;
};

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

void reversefn_linked_list (struct llNode **head, int n)
{
    struct llNode *last = *head, *first = NULL, *second = NULL;

    //setup
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
    while (first != NULL && first != last)
    {
        first->next = last->next;
        last->next = first;
        first = second;
        second = second->next;
    }

}


int main ()
{

    struct llNode *head = NULL;
    char vector [][10] = {"alfa", "beta", "gamma", "delta", "zeta", "eta", "theta", "iota", "kappa", "lambda"};


    struct llNode *node = create_node ("marco");
    push_node (&head, node);


    for (int i = 0; i < 10; i++)
    {
        push_node (&head, create_node (vector[i]));
    }
    print_linked_list(head);


    reversefn_linked_list (&head, 5);
    print_linked_list (head);


    free_linked_list (&head);


    return 0;
}