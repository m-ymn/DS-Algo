#include <stdio.h>
#include <stdlib.h>

#define CAP 5 //pre processor macro

void push(int) ;
int pop(void) ;
void traverse(void) ;
void peek(void);
int isfull(void) ;
int ismepty(void) ;

int stk[CAP], top = -1 ;

void main()
{
    int ch, item ;
    while(1)
    {
    printf("1. PUSH \n2. POP \n3. PEEK\n4. Traverse \n5.Quit\n");
    printf("Enter your choice: ") ;
    scanf("%d", &ch) ;

    switch(ch)
    {
    case 1 : printf("enter element to push: ");
             scanf("%d",&item) ;
             push(item);
             break ;
    case 2 : item = pop() ;
                if(item ==0)
                {
                    printf("stack is underflow\n");
                }
                else
                {
                    printf("popped items is: %d \n", item) ;
                }
                break ;
    case 3 : peek() ;
             break ;
    case 4 : traverse() ;
            break ;
    case 5 : exit(0) ;
    default : printf("invalid input \n") ;
    }
    }
}

void push(int ele)
{
    if (isfull())
    {
        printf("Stack is full") ;
    }
    else
    {
     top++ ;
     stk[top] = ele ;
     printf("element inserted is %d \n",ele) ;
    }
}
int pop()
{
    if (isempty())
    {
        printf("stack is underflow \n") ;
    }
    else
    {
        return stk[top--] ; // first it will return top value & then it will decre
    }
}
void peek()
{
    if(isempty())
    {
        printf("stack is empty\n") ;
    }
    else
    {
        printf("peek ele :%d\n", stk[top]) ;
    }
}
void traverse()
{
    if(isempty())
    {
        printf("no element\n") ;
    }
    else
    {
    int i ;
    printf("stack ele : \n");
    for(i=0;i<=top;i++)
        {
            printf("%d \n", stk[i]) ;
        }
    }
}

int isfull()
{
    if(top == CAP - 1)
    {
        return 1 ;
    }
    else
    {
     return 0 ;
    }
}

int isempty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0 ;
    }
}
