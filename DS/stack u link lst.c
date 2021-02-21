#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data ;
    struct node *lnk ;
}SN;
SN *top = NULL ; // defining top pointer

void push() ;
void pop() ;
void display() ;

void main()
{
    int ch ;
    while(1)
    {
        printf("Stack Ops using Linked List\n") ;
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n") ;
        printf("Enter your choice: ") ;
        scanf("%d", &ch) ;
        switch(ch)
        {
            case 1 : push() ;
            break ;
            case 2 : pop() ;
            break ;
            case 3 : display() ;
            break ;
            case 4 : exit(1) ;
            default : printf("invalid input") ;
        }

    }


}

void push()
{
    SN *temp ;
    temp = (SN*)malloc(sizeof(SN)) ; // a node created
    temp->lnk = NULL ;  // pointing node to null
    printf("enter node data: ") ;
    scanf("%d" ,&temp->data) ;
    temp->lnk = top ; // node link pointing to top
    top = temp ; // top pointer will point to temp

}

void pop()
{
    SN *temp ;
    temp = top ;
    if(temp == NULL)
    {
        printf("Stack is empty\n") ;
    }
    else
    {
        printf("Deleted element is: %d\n",temp->data) ;
        top = top->lnk ; // moving top pointer forward one step
        temp->lnk = NULL ; // removing temp element link to top
        free(temp) ;
    }



}

void display()
{
    SN *temp ;
    temp = top ;
    while(temp != NULL)
    {
        printf("ele is %d\n",temp->data) ;
        temp = temp->lnk ;
    }

}
