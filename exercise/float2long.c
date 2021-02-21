#include <stdio.h>
#include <stdint.h>

void f2l(float * num) ;
long o = 254155 ;

void main()
{


    float a  = 27.8 ; // input
    printf("enter float num: ") ;
    scanf("%f",&a) ;
    //printf("entered num is %lu\n",o) ;
    f2l(&a) ;

    /*
            1mm = 8000pulses / 4mm lead
              = 2000 pulses //multiplying factor
        0.001mm  = 2000 * 0.001
                = 2 pulses


    */
}

void f2l(float *num)
{
    // PPR = lead/ linear resolution
    //ppr = 8000  lead = 4mm  resolution = 0.0005mm
   // printf("%f\n",*num);
    o = (long)((*num) * 8000 );  //
    printf("num is %lu\n",o) ;

}
