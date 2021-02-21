#include <stdio.h>
#include <string.h>
#include <stdbool.h>



void main()
{
    int a , b, ch ;
    while(1)
    {
    printf("Enter operation to perform: ") ;
    printf("\n1.AND \n2. OR\n3. NOT\n4. XOR\n5. XNOR\n6. Quit\n") ;
    scanf("%d",&ch) ;
    switch(ch)
    {
        case 1 : AND() ;
                break ;
        case 2 : OR(a,b) ;
                break ;
        case 3 : NOT(a) ;
                break ;
        case 4 : XOR(a,b);
                break ;
        case 5 : XNOR(a,b) ;
                break ;
        case 6 : exit(1) ;
        default : printf("Invalid Choice\n") ;
    }
    }
}

int AND()
{
    int a, b ;
    printf("Enter two elements for logic operation :") ;
    scanf("%d", &a) ;
    scanf("%d", &b) ;
    if(a == 1 && b == 1)
        printf("%d\n", 1) ;
    else
        printf("%d\n", 0) ;
}

int OR()
{
    int a, b ;
    printf("Enter two elements for logic operation :") ;
    scanf("%d", &a) ;
    scanf("%d", &b) ;
    if(a == 1 || b == 1)
         printf("%d\n", 1) ;
    else
        printf("%d\n", 0) ;
}

int NOT()
{
    int a ;
    printf("Enter element for logic operation :") ;
    scanf("%d", &a) ;
    if(a)
        printf("%d\n", 0) ;
    else
         printf("%d\n", 1) ;
}

int XOR()
{
    int a, b ;
    printf("Enter two elements for logic operation :") ;
    scanf("%d", &a) ;
    scanf("%d", &b) ;
    if((a == 1 && b == 0) || (a==0 || b==1))
         printf("%d\n", 1) ;
    else
        printf("%d\n", 0) ;
}

int XNOR()
{
    int a, b ;
    printf("Enter two elements for logic operation :") ;
    scanf("%d", &a) ;
    scanf("%d", &b) ;
    if((a == 1 && b == 0) || (a==0 || b==1))
         printf("%d\n", 0) ;
    else
         printf("%d\n", 1) ;
}

