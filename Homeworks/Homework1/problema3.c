#include <stdio.h>


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

void ninit (struct Node *n, int key)
{
    if (n == NULL)

        return;

    n->key = key;
    n->priority = 0;

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

}

void right_rotate (struct Node *node)
{

}

void treap_insert (struct Node *tree, struct Node *node)
{
    //inserisco prima in posizione, dopo aggiusto in caso di priorita' non rispettata

}



int main ()
{
    struct Node *tree = NULL;

    struct Node node1;
    ninit (&node1, 10);
    tree_insert (&tree, &node1);
    printf ("Stampo il PRIMO inserimento:\n");
    nprint (tree);

    struct Node node2;
    ninit (&node2, 22);
    tree_insert (&tree, &node2);

    printf ("Stampo RADICE dopo il SECONDO inserimento:\n");
    nprint (tree);
    printf ("Stampo FIGLIO SINISTRO DELLA RADICE dopo il SECONDO inserimento:\n");
    nprint (tree->left);
    printf ("Stampo FIGLIO DESTRO DELLA RADICE dopo il SECONDO inserimento:\n");
    nprint (tree->right);

    struct Node node3;
    ninit (&node3, 33);
    tree_insert (&tree, &node3);
    printf ("Stampo il MASSIMO dopo il TERZO inserimento:\n");
    nprint (tree->right->right);


    struct Node node4;
    ninit (&node4, 3);
    tree_insert (&tree, &node4);
    printf ("Stampo il NODO4:\n");
    nprint (tree->left);

    return 0;
}