#include <stdio.h>
#include <stdint.h>


int arr1[] = {1,0,0,4,5,0,2,3,1,6,7,1,0} ;

/*
        first condition is to run the loop and also emit the 0 condition
        calc the well width and then area can be calc area
        subtract the occupied spaces from area and u get free blocks

*/
int spaces ;

void main()
{
    int sze = sizeof(arr1)/sizeof(arr1[0]) ;
    int ptr=0,ptr2 = 0;
    int *aptr = arr1 ;
    //int * parr = arr ;
    while(ptr < sze)
    {
        ptr2 = fxn(ptr,aptr) ;
        ptr = ptr2 ;
    }
    printf("Total spaces : %d", spaces);

}

int fxn(int ap1,int * arr)
{
    int sze = sizeof(arr1)/sizeof(arr1[0]) ;
    int width = 0, i=0  ;
    int ap2, area ;
    while(arr[ap1] == 0)
    {
        ap1++;
    }
    ap2 = ap1 + 1 ;
    printf("pointer 1: %d\n",arr[ap1]);
    while(arr[ap1] >= arr[ap2] && ap2 < sze)  //
    {
        ap2++ ;   // finding ap2
    }
    if(arr[ap2] >= arr[ap1])
        {
        printf("pointer 2: %d\n",arr[ap2]);
        width = ap2-ap1-1 ;
        printf("width:%d\n" , width) ;
        if(arr[ap2] <= arr[ap1])
            area = width * arr[ap2] ;
        else
            area = width * arr[ap1] ;
        printf("area is %d\n", area) ;
        //ap1++ ;
        for(i = ap1+1;i<ap2;i++)
        {
            if(arr[i] !=0)
                area = area - arr[i] ;
        }
        printf("area left: %d\n", area) ;
    }
    spaces += area ;
    return ap2 ;
}
