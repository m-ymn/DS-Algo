
/*Single linked list ops*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node* lnk ;

};
struct node* root = NULL ;

int len ;

void append(void) ;
void addatbegin(void) ;
void addatmid(void) ;
void display(void) ;
int length(void) ;
void delete1(void) ;
void swap() ;

void main()
{
    int ch ;
    while(1)
    {
        printf("single linked list ops\n") ;
        printf("1. Append\n") ;
        printf("2. Add at begin\n") ;
        printf("3. Add at Mid\n") ;
        printf("4. Length\n") ;
        printf("5. Display\n") ;
        printf("6. Delete\n7. Swap\n") ;
        printf("8. Quit\n") ;
        printf("Enter your choice: ") ;
        scanf("%d", &ch) ;

        switch(ch)
        {
            case 1 : append() ;
                    break ;
            case 2 : addatbegin();
                    break ;
            case 3 : addatmid();
                    break ;
            case 4 : len = length() ;
                    printf("Length of list is: %d\n", len) ;
                    break ;
            case 5 : display() ;
                    break ;
            case 6 : delete1() ;
                    break ;
            case 7 : swap() ;
                    break ;
            case 8 : exit(1) ;
            default : printf("Invalid character \n") ;
        }
    }
}

void append()
{
    struct node* temp ;
    temp = (struct node*)malloc(sizeof(struct node)) ;
    printf("enter data of node: ") ;
    scanf("%d",&temp->data) ;
    temp->lnk = NULL ;
    if(root == NULL)
    {
        root = temp ;
    }
    else
    {
        struct node* temp2 ;
        temp2 = root ;
        while (temp2->lnk != NULL)
        {
            temp2 = temp2->lnk ;
        }
        temp2->lnk = temp ;
    }
}

int length()
{
    int cnt = 0 ;
    struct node* temp ;
    temp = root ;
    while(temp != NULL)
    {
        cnt++ ;
        temp = temp->lnk ;
    }
    return cnt ;
}

void display()
{
    struct node* temp ;
    temp = root ;
    if (temp == NULL)
    {
        printf("list is empty\n") ;
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->",temp->data) ;
            temp = temp->lnk ;
        }
        printf("\n\n") ;
    }
}

void addatbegin()
{
    struct node *temp ;
    temp = (struct node*)malloc(sizeof(struct node)) ;
    printf("enter node data: ");
    scanf("%d", &temp->data) ;
    temp->lnk = root ;
    root = temp ;

}
void addatmid()
{
    int loc, len, i = 1 ;
    len = length() ;
    printf("enter location: ") ;
    scanf("%d", &loc) ;
    struct node *temp, *p ;
    if(loc > len)
    {
        printf("Invalid location\n") ;
        printf("length of list is %d \n", len) ;
    }
    else
    {
        p = root ;
        while(i < loc)
        {
            p = p->lnk ;
            i++ ;
        }
        temp = (struct node*)malloc(sizeof(struct node)) ;
        printf("enter node data: ") ;
        scanf("%d", &temp->data) ;
        temp->lnk = NULL ;
        temp->lnk = p->lnk ; //right side cnxn first
        p->lnk = temp ;  //left side cnexn

    }

}

void delete1()
{
   int loc ;
   printf("enter location to delete: ") ;
   scanf("%d",&loc) ;
   if(loc > length())
   {
       printf("Invalid Location") ;
   }
   else if(loc == 1)
   {
       struct node* temp ;
       temp = root ;
       root = temp->lnk ;
       temp->lnk = NULL ;
       printf("deleted node is %d\n",temp->data) ;
       free(temp) ;
   }
   else
   {
       struct node *p, *q  ;
       p = root ;
       int i = 1 ;
       while(i<loc-1)    //traversing upto the node before deletion
       {
           p = p->lnk ;
           i++ ;
       }
       q = p->lnk ; // q will point to the node to be deleted
       p->lnk = q->lnk ; // joining p with node after q
       q->lnk = NULL ; // q node now pointing to NULL
       printf("Deleted node is: %d\n",q->data) ;
       free(q) ; // freeing m/m hold by q node

   }

}
void swap()
{
    int loc,  len, i = 1 ;
    len = length() ;
    printf("enter location : ") ;
    scanf("%d", &loc) ;
    if(loc > len)
    {
        printf("Invalid location");
    }
    else
    {
        struct node *p, *q, *r ;
        p = root ;
        while(i<loc-1)
        {
            p = p->lnk ;
            i++ ;
        }
        q = p->lnk ;
        r = q->lnk ;
        p->lnk = r ;     // simple logic is not letting
        q->lnk = r->lnk ; //any node alone
        r->lnk = q ;
    }
}



