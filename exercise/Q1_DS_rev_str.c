#include <stdio.h>
#include <conio.h>
#include <string.h>



void main()
{
    rev() ;

}

void rev()
{
    char str[5] ;
    printf("Enter a string upto 10 chars: ") ;
    scanf("%s", &str) ;
    int n = strlen(str);
    char r_str[n] ;
    for (int i = 0; i<n; i++)
    {
        r_str[i] = str[n-i-1] ;
        //printf("%c\t",r_str[i]) ;
    }
    r_str[n] = '\0' ;
    printf("\nReverse String is %s",r_str) ;
    //int p = strcmp(str,r_str) ;
   // if(p == 0)
   if(strcmp(str,r_str) == 0)
    {
        printf("\nstring is palindrome") ;
    }
    else
        printf("\nString is not palindrome") ;

}
