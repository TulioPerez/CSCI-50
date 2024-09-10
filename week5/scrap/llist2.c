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

    node *lastNode = NULL; // Keep track of the last node

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



        // If the list is empty, set both list and lastNode to the new node
        if (list == NULL)
        {
            list = n;
            lastNode = n;
        }
        else
        {
            // Otherwise, add the new node to the end
            lastNode->next = n;
            lastNode = n;
        }

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
