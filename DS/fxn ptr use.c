

#include <stdio.h>

void a()
{
    printf("hello pointer") ;
}
void B(void (*ptr)())
{
    ptr() ;  // call back function
}

int main()
{
    B(&a) ;   // a is the function being passed to
        // B is fxn taking fxn potr as argument and then calling it

}
