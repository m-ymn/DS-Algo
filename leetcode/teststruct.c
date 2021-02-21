#include <stdio.h>


struct ynm
{
    int * y;
    int arr[10];
    float p;
}z;

int main()
{
    int x = 44;
  //  struct ymn z;
    printf("%d\n",&x);
    z.y = &x;

    z.arr[0] = 88;
    printf("%d\n",z.y);
    int * f = (int *) (&z);
    f+= 4;
    printf("f[0] =%d",*f);

    //*f = 55;
    //*z.y = 77;
    printf("\nx = %d\n",x);
    return 0;
}
