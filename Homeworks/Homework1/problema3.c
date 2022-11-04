#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Node
{
    int key;
    int priority;
    struct Node *left, *right, *parent;
};

void nprint (struct Node *n)
{
    if (n == NULL)
    {
        printf ("STAMPA DI UN NULLO\n");
        return;
    }

    printf ("NodeAddr: %p, key: %d, prio: %d, left: %p, righ: %p, pare: %p\n", n,  n->key, n->priority, n->left, n->right, n->parent);
}

void ninit (struct Node *n, int key, int prio)
{
    if (n == NULL)

        return;

    n->key = key;
    n->priority = prio;

    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
}

void tree_insert (struct Node **tree, struct Node *node)
{
    struct Node *followed = *tree;
    struct Node *follower = NULL;

    if (node == NULL) return;

    if (*tree == NULL)

        *tree = node;

    else
    {
        while (followed != NULL)
        {
            follower = followed;

            if (node->key < (followed)->key)
            
                followed = (followed)->left;
            
            else

                followed = (followed)->right;
        }

        node->parent = follower;
        
        if (node->key < follower->key)

            follower->left = node;

        else

            follower->right = node;
    }
}

void left_rotate (struct Node *node)
{
    struct Node *pivot = node->parent;

    if (pivot == NULL)  return;

    pivot->right = node->left;

    if (node->left != NULL)
    
        node->left->parent = pivot;

    node->parent = pivot->parent;

    if (pivot->parent != NULL)
    {
        if (pivot == pivot->parent->left)
        
            pivot->parent->left = node;

        else

            pivot->parent->right = node;
    }

    node->left = pivot;
    pivot->parent = node;
}

void right_rotate (struct Node *node)
{
    struct Node *pivot = node->parent;

    if (pivot == NULL) return;

    pivot->left = node->right;

    if (node->right != NULL)
   
        node->right->parent = pivot;

    node->parent = pivot->parent;

    if (pivot->parent != NULL)
    {
        if (pivot == pivot->parent->left)

            pivot->parent->left = node;

        else

            pivot->parent->right = node;

    }

    node->right = pivot;
    pivot->parent = node;
}

void treap_insert (struct Node **tree, struct Node *node)
{
    //inserisco prima in posizione, dopo aggiusto in caso di priorita' non rispettata

    tree_insert (tree, node);

    while (node->parent != NULL && node->parent->priority >= node->priority)
    {
        if (node == node->parent->left)

            right_rotate (node);

        else

            left_rotate (node);
    }

    if (node->parent == NULL)

        *tree = node;
}


void tprint (struct Node *tree)
{
    if (tree != NULL)
    {
        tprint (tree->left);

        //stampo il nodo
        nprint (tree);

        //stampo in caso di nodo foglia
        if (tree->left == NULL && tree->right == NULL)
        
            printf ("Foglia.\n");

        tprint (tree->right);
    }
}



int main ()
{
    srand(time(0));

    struct Node *tree = NULL;

    struct Node node1;
    ninit (&node1, 10, rand() % 100);
    tree_insert (&tree, &node1);
    //printf ("Stampo il PRIMO inserimento:\n");
    //nprint (tree);

    struct Node node2;
    ninit (&node2, 22, rand() % 100);
    treap_insert (&tree, &node2);

    /*
    printf ("Stampo RADICE dopo il SECONDO inserimento:\n");
    nprint (tree);
    printf ("Stampo FIGLIO SINISTRO DELLA RADICE dopo il SECONDO inserimento:\n");
    nprint (tree->left);
    printf ("Stampo FIGLIO DESTRO DELLA RADICE dopo il SECONDO inserimento:\n");
    nprint (tree->right);
    */

    struct Node node3;
    ninit (&node3, 33, rand() % 100);
    treap_insert (&tree, &node3);
    //printf ("Stampo il MASSIMO dopo il TERZO inserimento:\n");
    //nprint (tree->right->right);


    struct Node node4;
    ninit (&node4, 3, rand() % 100);
    treap_insert (&tree, &node4);
    //printf ("Stampo il NODO4:\n");
    //nprint (tree->left);


    struct Node node5;
    ninit (&node5, 11, rand() % 100);
    treap_insert (&tree, &node5);


    struct Node node6;
    ninit (&node6, 8, rand() % 100);
    treap_insert (&tree, &node6);

    struct Node node7;
    ninit (&node7, 17, rand() % 100);
    treap_insert (&tree, &node7);

        struct Node node8;
    ninit (&node8, 9, rand() % 100);
    treap_insert (&tree, &node8);

    tprint (tree);

    return 0;
}