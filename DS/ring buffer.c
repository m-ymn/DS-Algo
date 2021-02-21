#include <stdio.h>
#include <stdint.h>




typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int maxlen;
} circ_buf;


#define CIRC_BBUF_DEF(x,y)                \
    uint8_t x##_data_space[y];            \
    circ_buf x = {                     \
        .buffer = x##_data_space,         \
        .head = 0,                        \
        .tail = 0,                        \
        .maxlen = y                       \
    }


CIRC_BBUF_DEF(my_circ_buf, 32);

int circ_bbuf_push(circ_buf *c, uint8_t data) ;
int circ_bbuf_pop(circ_buf *c, uint8_t *data) ;
int circ_buf_display(circ_buf *c);

void main()
{
    uint8_t out_data=0, in_data = 0,ch ;
      while(1)
    {
        printf("\n**Circular Buffer Ops**") ;
        printf("\n1. Push DATA \n2. POP DATA \n3. Display BUFF \n4. Quit\n");
        printf("Enter your choice: ") ;
        scanf("%d", &ch) ;

    switch(ch)
    {
        case 1 : printf("Enter element to push: ");
                scanf("%d",&in_data) ;
                circ_bbuf_push(&my_circ_buf, in_data);
                break ;
        case 2 : circ_bbuf_pop(&my_circ_buf, &out_data) ;
                printf("\nDeleted Element is: %d",out_data) ;
                break ;
        case 3 : circ_buf_display(&my_circ_buf) ;
                break ;
        case 4 : exit(0) ;
        default : printf("\ninvalid input \n") ;
    }
    }


}

int circ_bbuf_push(circ_buf *c, uint8_t data)
{
    int next;

    next = c->head + 1;  // next is where head will point to after this write.
    if (next >= c->maxlen)
        next = 0;

    if (next == c->tail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    c->buffer[c->head] = data;  // Load data and then move
    c->head = next;             // head to next data offset.
    return 0;  // return success to indicate successful push.
}

int circ_bbuf_pop(circ_buf *c, uint8_t *data)
{
    int next;

    if (c->head == c->tail){  // if the head == tail, we don't have any data
        printf("buffer empty\n\r");
        return -1;
    }
    next = c->tail + 1;  // next is where tail will point to after this read.
    if(next >= c->maxlen)
        next = 0;

    *data = c->buffer[c->tail];  // Read data and then move
    c->tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}

int circ_buf_display(circ_buf *c)
{
    if (c->head == c->tail)  // if the head == tail, we don't have any data
        printf("BUFF empty\n\r");
        return -1;
    int *ptr ;
    for(ptr=c->tail; ptr <= c->head;ptr++)
    {
        printf("data: %d", *ptr);
        //c->tail++ ;
    }
    return 0 ;
}



