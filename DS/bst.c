#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data ;
    struct node *Rch ;
    struct node *Lch ;
}SBN;
SBN *root = NULL ; // defining root

int* delet(SBN *,int) ;
void insert();
void inOrder(SBN*) ;
void display() ;
int* minVal(SBN*) ;
void postOrder(SBN *root) ;
void preOrder(SBN *root) ;

void main()
{
    int ch ;
    while(ch)
    {
        printf("\nBINARY SEarch TRee OPs\n");
        printf("1. Insert\n2. Display\n3. Delete\n4. Quit\n") ;
        printf("Enter your choice: ") ;
        scanf("%d", &ch) ;
        switch(ch)
        {
            case 1 : insert() ;
                    break ;
            case 2 : display() ;
                    break ;
            case 3 : printf("Enter element to delete: ") ;
                    int i ;
                    scanf("%d" ,&i) ;
                    delet(root,i) ;
                    break ;
            case 4 : exit(1) ;
            default : printf("Invalid choice\n");
        }
    }
}

void insert()
{
    int d ;
    SBN *temp, *p ;// p is parent node
    printf("Enter integer node data: ") ;
    scanf("%d",&d) ;
    temp = (SBN*)malloc(sizeof(SBN)) ;
    temp->data = d ;
    temp->Rch = NULL ;
    temp->Lch = NULL ;
    p = root ;
    if(root == NULL)
    {
        root = temp ;
    }
    else
    {
        SBN *cur ;
        cur = root ;
        while(cur)  // finding parent node
        {
            p = cur ;
            if(temp->data > cur->data)
            {
                cur = cur->Rch ;
            }
            else
            {
                cur = cur->Lch ;
            }
        }
        if(temp->data > p->data )
        {
            p->Rch = temp ;
        }
        else
        {
            p->Lch = temp ;
        }
    }
}

int* delet(SBN *root,int data)
{
    if (root == NULL)
    {
        printf("Element not present") ;
        return root;
    }
    if (data < root->data) //traversing
    {
        root->Lch = delet(root->Lch, data);
    }
    else if (data > root->data)
    {
        root->Rch = delet(root->Rch, data);
    }

    else
    {
        // node with only one child or no child
        if (root->Lch == NULL)
        {
            SBN *temp = root->Rch;
            free(root);
            return temp;
        }
        else if (root->Rch == NULL)
        {
            SBN *temp = root->Lch;
            free(root);
            return temp;
        }
        // node with two children: Get the min value successor (smallest
        // in the right subtree)
        SBN *temp = minVal(root->Rch);
        root->data = temp->data;
        root->Rch = delet(root->Rch, temp->data);
    }
    return root ;
}

int* minVal(SBN* root)
{
    SBN* crnt = root;
    while (crnt && crnt->Lch != NULL)
    {
        crnt = crnt->Lch;
    }
    return crnt;
}

void inOrder(SBN *root)
{
    if(root!=NULL)
    {
        inOrder(root->Lch);
        printf("%d-->",root->data);
        inOrder(root->Rch);
    }
}
void postOrder(SBN *root)
{
    if(root != NULL)
    {
        postOrder(root->Lch) ;
        postOrder(root->Rch) ;
        printf("%d-->", root->data) ;

    }
}
void preOrder(SBN *root)
{
    if(root != NULL)
    {
        printf("%d-->", root->data) ;
        postOrder(root->Rch) ;
        postOrder(root->Lch) ;
    }
}
void display()
{
    if(root!=NULL)
    {
       printf("\nPostOrder: ") ;
       postOrder(root) ;
       printf("\nPreOrder: ") ;
       preOrder(root) ;
       printf("\nInOrder: ") ;
       inOrder(root) ;
    }
    else
    {
        printf("Tree is Empty\n");
    }

}


