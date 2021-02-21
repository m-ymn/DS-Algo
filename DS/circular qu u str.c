
/*Circular Queue using Structures */

#include<stdio.h>
#include<conio.h>

#define size 6



typedef struct cir_q
{
    int front ;
    int rear ;
    int qu[6] ;
}CQu ;

CQu cq;

void main()
{

    cq.front = -1 ;
    cq.rear = -1 ;

    int ch, item ;
    while(1)
    {
        printf("\n**Circular Queue Ops**") ;
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Quit\n");
        printf("Enter your choice: ") ;
        scanf("%d", &ch) ;

    switch(ch)
    {
        case 1 : printf("Enter element to push: ");
                scanf("%d",&item) ;
                insert(item);
                break ;
        case 2 : printf("\nDeleted Element is: %d",delet()) ;
                break ;
        case 3 : display() ;
                break ;
        case 4 : exit(0) ;
        default : printf("\ninvalid input \n") ;
    }
    }
}

void insert(int ele)
{
    if((cq.front == 0 && cq.rear == size-1) ||
            (cq.rear == (cq.front-1)%(size-1)))
    {
        printf("\nCircular Queue is full\n");
    }
    else if(cq.front == -1 && cq.rear == -1)
    {
        cq.front = cq.rear = 0 ;
        cq.qu[cq.rear] = ele ;

    }
    else if(cq.rear == size-1)
    {
        cq.rear = 0 ;
        cq.qu[cq.rear] = ele ;
    }
    else
    {
        cq.rear++ ;
        cq.qu[cq.rear] = ele ;
    }
}

int delet()
{
    int ele ;
    if(cq.front == -1 && cq.rear == -1)
    {
        printf("\nQueue is Empty") ;
    }
    else if(cq.front == cq.rear) // deleting last ele
    {
        ele = cq.qu[cq.front] ;
        cq.front = cq.rear = -1 ;

    }
    else if(cq.front == size-1)
    {
        ele = cq.qu[cq.front] ;
        cq.front = 0 ;
    }
    else
    {
        ele = cq.qu[cq.front] ;
        cq.front++ ;
    }
    return ele ;
}


void display()
{
    if(cq.front == -1 && cq.rear == -1)
    {
        printf("\nQueue is Empty") ;
    }
    else if (cq.rear >= cq.front)
    {
        for (int i = cq.front; i <= cq.rear; i++)
            printf("%d ",cq.qu[i]);
    }
    else
    {
        for (int i = cq.front; i < size; i++)
            printf("%d ", cq.qu[i]);

        for (int i = 0; i <= cq.rear; i++)
            printf("%d ", cq.qu[i]);
    }

}
