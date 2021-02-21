
#ifndef STK_H_
#define STK_H_


typedef struct{
    int *elems;  // address of a array object
    int logic_len ;
    int alloc_len ;

} stak ;

void stack_new(stak *s) ;
void stack_dis(stak *s) ;
void stack_push(stak *s, int val) ;
int stack_pop(stak *s) ;











#endif
