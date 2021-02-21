#include <stdio.h>
#include <stdint.h>



int add1(int a, int b)
{
    return a+b ;
}

int mult(int a , int b)
{
    return a*b ;
}

//int(*f_ptr)(int,int) ;

typedef int(*f_ptr)(int,int) ;

int call(f_ptr func,int a, int b)
{
    return func(a,b) ;
}
int call2(int(*func)(int,int),int a, int b)  // takes fxn pointer as input and args
{
    return func(a,b) ;
}


int main()
{

    int r ;
    //f_ptr = &add1 ;
    f_ptr add2 = add1 ;  // add2 is a fxn of type int(int,int)
    r = add2(20,30) ;
  //  r = f_ptr(20,30) ;


   // r = call(mult,10,20) ;
    //printf("F_ptr: %d",r) ;
    //r = call2(mult,10,20) ;
    printf("F_ptr: %d",r) ;


    return 0 ;

}
