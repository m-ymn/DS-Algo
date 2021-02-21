#ifndef STK1_H_INCLUDED
#define STK1_H_INCLUDED


typedef struct{
    int *elems;  // address of a array object
    int logic_len ;
    int alloc_len ;

} stak ;

void stack_new(stak *s) ;
void stack_dis(stak *s) ;
void stack_push(stak *s, int val) ;
int stack_pop(stak *s) ;





#endif // STK1_H_INCLUDED
