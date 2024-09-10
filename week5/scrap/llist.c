#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

// Defines the max number of nodes
int MAXNODES = 7;

int main(void)
{
    node *list = NULL;
    int totalNodes = 0;

    while (totalNodes < MAXNODES)
    {
        int x = get_int("Number: ");
        if (x == INT_MAX)
        {
            printf("\n");
            break;
        }

        // Allocate a new node.
        node *n = malloc(sizeof(node));
        n->number = x;
        n->next = NULL;

        // TODO: Modify the below to add new nodes to the end of a linked list, rather than the beginning.
        // As a result, the list of numbers should now print out in order, instead of reverse order.
        n->next = list;
        list = n;

        // Update the total number of nodes
        totalNodes++;
    }

    // Print all nodes.
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free all nodes.
    node *ptr = list;
    while (ptr != NULL)
    {
        node *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
}