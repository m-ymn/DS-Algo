#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>
//#include "stk1.h"

int main()
{
   /* stak s ;
    stack_new(&s) ;
    for(int i=0;i<5;i++)
    {
        stack_push(&s,i);
    }
    stack_dis(&s) ;
*/
    const char* friends[] = {"amaaxing","empty"} ;

    char* d = strdup(friends[0]) ;

    printf("%s ",d);
    d = strdup(friends[1]) ;

    printf("%s",d);
    return 0;
}
/*
void stack_new(stak *s)
{
    s->logic_len = 0;
    s->alloc_len = 4;
    s->elems = malloc(4*sizeof(int)) ; //in heap 16 byts
    assert(s->elems != NULL) ; //if malloc fails
}

void stack_dis(stak *s)
{
    free(s->elems) ;
}


void stack_push(stak* s,int val)
{
    if(s->logic_len == s->alloc_len)
    {
        s->alloc_len *= 2 ; //doubling length
        // realloc is time consuming
        s->elems = realloc(s->elems,s->alloc_len*sizeof(int));
        assert(s->elems != NULL) ; //
    }

    s->elems[s->logic_len] = val ;
    s->logic_len++ ;
}

int stack_pop(stak *s)
{
    assert(s->logic_len > 0) ;
    s->logic_len-- ;
    return s->elems[s->logic_len] ;
}

*/
