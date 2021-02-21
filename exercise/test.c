
#include <stdio.h>
#include <stdint.h>


// the task is to find the longest gap of 0's in a binary representation of number

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <math.h>

int main()
{
    solution(32) ;

}


int solution(int N) {
    unsigned int i=0 , cnt = 0 ,n2=0;
    unsigned int st =0 ;
    // array to store binary number
    int a[64];

    // counter for binary array
    while (N > 0) {
        // storing remainder in binary array
        a[i] = N % 2;
        N = N / 2;
        //printf("%d", a[i]) ;
        i++;

    }
    a[i] = 2;
    //len = (int)log2(N)+1;
    i=0 ;
    //printf("%d\n", len);

    while(a[i] != 2)
    {
        //printf("%d,",a[i]) ;
        i++;
    }
    i=0 ;

    while(a[i] != 2)
    {
        if(a[i] == 1 && st == 0) // start condition
        {
            cnt = 0 ;
            st = 1 ;
        }
        if(a[i] == 0 && st == 1)  //
        {
            cnt++ ;
        }
        if(a[i] == 1 && st == 1)  // end condition
        {
            if(cnt > n2)
            {
                n2 = cnt ;
            }

            //st = 0 ;
            cnt = 0 ;
        }
        i++ ;
    }

    printf("%d\n", n2);


    return n2 ;



    // write your code in C99 (gcc 6.2.0)
}
