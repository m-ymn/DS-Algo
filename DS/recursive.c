#include <stdio.h>
#include <stdlib.h>


int fib(int n)
{
    if(n<=1)
        return 1 ;

    return fib(n-1) + fib(n-2) ;
}


void main()
{
    printf("the number is: %d \n", fib(10)) ;

}
