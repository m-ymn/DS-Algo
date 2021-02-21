#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int data;
    int pri;  // Lower values indicate higher priority
    struct node* lnk;
} SPN;

SPN* root = NULL ;

SPN* newNode(int d, int p) // Function to Create A New Node
{
    SPN* temp = (SPN*)malloc(sizeof(SPN));
    temp->data = d;
    temp->pri = p;
    temp->lnk = NULL;

    return temp;
}

void main()
{
     // Create a Priority Queue
    // 7->4->5->6
    if (root == NULL)
    {
        root = newNode(4, 1);
        push(5, 2);
        push(6, 3);
        push(7, 4);
        push(22,0) ;
        push(81, 3) ;
    }

    SPN *p = root ;
    if (p == NULL)
    {
        printf("list is empty\n") ;
    }
    else
    {
        while(p != NULL)
        {
            printf("%d-->",peek()) ;
            pop() ;

        }
        printf("\n") ;
    }
}

// Return the value at head
int peek()
{
    SPN *p = root ;
    return p->data ;
}

// Removes the element with the
// highest priority form the list
void pop()
{
    SPN* temp = root;
    temp = temp->lnk;
    root = temp ;
    free(temp);
}

// Function to push according to priority
void push(int d, int p)
{
    SPN* start = root;

    // Create new Node
    SPN* temp = newNode(d, p);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if (start->pri > p) {

        // Insert New Node before head
        temp->lnk = root;
        root = temp;
    }
    else {

        // Traverse the list and find a
        // position to insert new node
        while (start->lnk != NULL &&
               start->pri < p)
               {
                start = start->lnk;
                }
            // Either at the ends of the list
            // or at required position
        temp->lnk = start->lnk;
        start->lnk = temp;
    }
}

// Function to check is list is empty
