
/*String Reverse using stack*/

#include <stdio.h>
#include <conio.h>
#include <string.h>


char str[30] ;
char stk[30] ;
char r_str[30] ;

int top = -1 ;

void main()
{

    printf("Enter a string upto 10 chars: ") ;
    scanf("%s", &str) ;
    int n = strlen(str);
    for (int i = 0; i< n; i++)
    {
        top++ ;
        stk[top] = str[i] ;
    }
    int i = 0 ;
    while(top != -1)
    {
        r_str[i] = stk[top] ;
        printf("%c",stk[top]) ;
        top-- ;
        i++ ;
    }
    if(strcmp(str,r_str) == 0)
    {
        printf("\nstring is palindrome") ;
    }
    else
        printf("\nString is not palindrome") ;

}






