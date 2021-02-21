#include <stdio.h>
#include <string.h>
#define CAP 8


char stk[CAP][10] ;
int top = -1 ;
char sstk[CAP][10] ;
int top2 = -1 ;
int loc[100] ;
int ltop = -1 ;


void main()
{
    int ch ;
    char item[10] ;
    while(1)
    {
        printf("\n**Undo Redo program**") ;
        printf("\n1. PUSH \n2. UNDO \n3. REDO \n4. Display\n5. EDIT\n6. Quit\n");
        printf("Enter your choice: ") ;
        scanf("%d", &ch) ;

        switch(ch)
        {
        case 1 : printf("Enter element to push: ");
                scanf("%s",&item) ;
                push(item);
                break ;
        case 2 : undo() ;
                break ;
        case 3 : redo() ;
                break ;
        case 4 : display() ;
                break ;
        case 5 : Edit() ;
                break ;
        case 6 : exit(0) ;
        default : printf("Invalid input \n") ;
        }
    }

}

void push(char ele[10])
{
    if (top == CAP-1)
    {
        printf("Stack is full\n") ;
    }
    else
    {
     top++ ;
     ltop++ ;
     strcpy(stk[top], ele) ;
    // printf("Element inserted is: %s \n",stk[top]) ;
    loc[ltop] = top ;
    }
}

void undo()
{
    if (top == -1)
    {
        printf("Nothing to undo\n") ;
    }
    else
    {

        strcpy(stk[loc[ltop]] , sstk[top2]) ;

        //strcpy(sstk[top2], stk[top]) ;
        top2-- ;
    }
}

void redo()
{
    if(top2 == -1)
    {
        printf("Nothing to redo\n");
    }
    else
    {
        //top++ ;
        strcpy(stk[loc[ltop]],sstk[top2]) ;
        top2-- ;
    }
}
void display()
{
    if(top == -1)
    {
        printf("\nNo element\n") ;
    }
    else
    {
        int i ;
        printf("stack ele : \n");
        for(i=0;i<=top;i++)
        {
            printf("%s ", stk[i]) ;
        }
    }
}

void Edit()
{
    int i = top ;
    printf("enter location to edit\n") ;
    scanf("%d", &i) ;
    if(top == -1 || i > top)
    {
        printf("Stack is empty or Invalid location\n") ;
    }
    else
    {
        char n_item[10] ;
        int ptop = top ;
        while(ptop != i-1)
            ptop-- ;
        loc[++ltop] = i ;
        printf("new data\n") ;
        scanf("%s",&n_item) ;
        top2++ ;
        strcpy(sstk[top2],stk[ptop]) ;
        strcpy(stk[ptop], n_item) ;
    }
}

