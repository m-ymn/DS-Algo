#include <stdio.h>
#include <stdint.h>


typedef union
{
    int val ;
    struct
    {
        int t:4 ;
    }sys;

}sysmod ;

typedef union
{
    int a ;
    char b ;
    double c ;
} data ;


int main(){
    //sysmod syt;
    data arr[10] ;
    arr[0].b = 100 ;
    arr[1].a = 5 ;
    printf("size of:%d", sizeof(arr)) ;
    return 1 ;
}
