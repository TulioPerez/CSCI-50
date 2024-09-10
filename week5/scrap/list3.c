#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    // create value container within node for int
    int number;

    // create node pointer within node
    struct node *next;
} node; // synonym for 'typedef struct node'


int main(int argc, char *argv[])
{
    // declare a linked list and initialize to null
    node *list = NULL;

    // do the following for the arguments entered at runtime
    for (int i = 1; i < argc; i++)
    {
        // convert *char (ascii) to int (to be entered into linkedlist)
        int number = atoi(argv[i]);

        // create chunk of memory that can fit the node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return 1;
        }
        // go to chunk of memory & make the number value within == argument value entered at runtime (after being converted to int from ascii above):
        n->number = number;

        // set node's 'next' field == whatever the list currently is i.e. insert this node in front of whatever is currently present
        n->next = list;

        // set list == the new higher value
        list = n;
    }

        // (print the linked list:
        // create pointer and set to first value in list (last value)
        node *ptr = list;
        while (ptr != NULL)
        {
            // print the number value being pointed to
            printf("%i\n", ptr->number);

            // set pointer to next pointer value
            ptr = ptr->next;
        }

}

// stopped lecture @ 1:20:045