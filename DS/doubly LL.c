#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data ;
    struct node *Rlnk ;
    struct node *Llnk ;
}SN;
SN *root = NULL ; // defining root

int len ;

void append(void) ;
void addatbegin(void) ;
void addinmid(void) ;
void display(void) ;
int length(void) ;
void delet(void) ;

void main()
{
    int ch ;
    while(1)
    {
        printf("\nDouble linked list ops\n") ;
        printf("1. Append\n") ;
        printf("2. Addbegin\n") ;
        printf("3. AddinMid\n") ;
        printf("4. length\n5. Display\n6. Delete\n7. Quit\n") ;
        printf("Enter your choice: ") ;
        scanf("%d", &ch) ;

        switch(ch)
        {
            case 1 : append() ;
                    break ;
            case 2 : addatbegin();
                    break ;
            case 3 : addinmid();
                    break ;
            case 4 : len = length() ;
                    printf("Length of list is: %d\n", len) ;
                    break ;
            case 5 : display() ;
                    break ;
            case 6 : delet() ;
                    break ;
            case 7 : exit(1) ;
            default : printf("Invalid character \n") ;
        }
    }
}

void append()
{
    SN *temp ;
    temp = (SN*)malloc(sizeof(SN)) ;
    printf("Enter Node Data: ") ;
    scanf("%d", &temp->data) ;
    temp->Llnk = NULL ;
    temp->Rlnk = NULL ;
    if(root == NULL)
    {
        root = temp ;
    }
     else
     {
         SN *p ;
         p = root ;
         while(p->Rlnk != NULL)
         {
             p = p->Rlnk ;
         }
         p->Rlnk = temp ;
         temp->Llnk = p ;
     }
}

void addatbegin()
{
    SN *temp ;
    temp = (SN*)malloc(sizeof(SN)) ;
    printf("Enter Node Data: ") ;
    scanf("%d", &temp->data) ;
    temp->Llnk = NULL ;
    temp->Rlnk = NULL ;
    if(root == NULL)
    {
        root = temp ;
    }
    else
    {
        temp->Rlnk = root ;
        root->Llnk = temp ;
        root = temp ;
    }
}

void addinmid()
{
    SN *temp, *p ;
    int loc, len , i = 1 ;
    len = length() ;
    printf("enter location: ") ;
    scanf("%d", &loc) ;
    if( loc > len)
    {
        printf("Invalid Location \n") ;
        printf(" Length of list is %d\n",len) ;
    }
    else
    {
        temp = (SN*)malloc(sizeof(SN)) ;
        printf("Enter Node Data: ") ;
        scanf("%d", &temp->data) ;
        temp->Llnk = NULL ;
        temp->Rlnk = NULL ;
        p = root ;
        while(i<loc)
        {
            p = p->Rlnk ;
            i++ ;
        }
        temp->Rlnk = p->Rlnk ;
        p->Rlnk->Llnk = temp ;  // right side cnxn over
        temp->Llnk = p ;
        p->Rlnk = temp ;
    }
}

void display()
{
    SN *temp = root ;
    if(temp == NULL)
    {
        printf("List is Empty\n") ;
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->", temp->data) ;
            temp = temp->Rlnk ;
        }

    }
}

int length()
{
   SN *temp = root ;
   int cnt = 0 ;
   while(temp != NULL)
   {
       cnt++ ;
       temp = temp->Rlnk ;
   }
   return cnt ;
}

void delet()
{
    int loc, len ;
    len = length() ;
    printf("enter location to delete: ") ;
    scanf("%d",&loc) ;
    if(loc > len)
    {
        printf("Invalid Location\n") ;
        printf("Length of list is %d\n", len) ;
    }
    else if(loc == 1)
    {
        SN* temp ;
        temp = root ;
        root = temp->Rlnk ;
        temp->Rlnk->Llnk = NULL ;
        temp->Rlnk = NULL ;
        printf("Deleted node is %d\n", temp->data) ;
        free(temp) ;
   }
   else if(loc == len)
   {
       SN *temp = root ;
       while(temp->Rlnk != NULL)
       {
           temp = temp->Rlnk ;
       }
       temp->Llnk->Rlnk = NULL ;
       temp->Llnk = NULL ;
       printf("deleted node is: %d", temp->data) ;
       free(temp) ;
   }
   else
   {
       SN *p, *q  ;
       p = root ;
       int i = 1 ;
       while(i<loc-1)    //traversing upto the node before deletion
       {
           p = p->Rlnk ;
           i++ ;
       }
       q = p->Rlnk ;
       q->Rlnk->Llnk = p->Rlnk ;
       p->Rlnk = q->Rlnk ;
       q->Llnk = NULL ;
       q->Rlnk = NULL ;
       printf("Deleted node is: %d\n",q->data) ;
       free(q) ; // freeing m/m hold by q node

   }

}
