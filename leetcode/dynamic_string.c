#include <stdio.h>
#include <stdint.h>



int main(){
    char arr[10];
    int * ptr = malloc(20*sizeof(int));
    int *p = ptr;
    p -= 1;
     printf("ptr = %d\n",ptr);
      printf("p%d\n",p);
    printf("bg%d\n",*p);

    return 0;

}
