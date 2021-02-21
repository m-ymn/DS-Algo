#include <stdio.h>
#include <stdint.h>

typedef enum
{
    STT_0 = 0, STT_1, STT_2, STT_3, STT_4
}STATES ;

typedef struct
{
    STATES state ;
}APP_DATA ;

APP_DATA appdata ;  // instance of state


int main()
{
    appdata.state = 0 ; // this is init state
    int c = 0 ;
    while(1)
    {
        int x = 0 ;

        switch(appdata.state)
        {

            case STT_0 :
                printf("THIS is init state.\n") ;
                scanf("%d", &x) ;
                (x == 1)?c++:c-- ;
                if(c == 1)
                    appdata.state = STT_1 ;
                break ;
            case STT_1 :
                printf("THIS is state 1.\n") ;
                scanf("%d", &x) ;
                (x == 1)?c++ :c-- ;

                if(c == 2)
                    appdata.state = STT_2 ;
                break ;
            case STT_2 :
                printf("THIS is state 2.\n") ;
                scanf("%d", &x) ;
                (x == 1)? c++:c-- ;
                if(c == 3)
                    appdata.state = STT_3 ;
                break ;
            case STT_3 :
                printf("THIS is state 3.\n") ;
                scanf("%d", &x) ;
                (x == 1)? c++:c-- ;
                if(c == 4)
                    appdata.state = STT_4 ;
                break ;
            case STT_4:
                printf("THIS is final state.\n") ;
                scanf("%d", &x) ;
                (x == 1)?c++:c-- ;
                if(c == 0)
                    appdata.state = STT_0 ;
                break ;
            default:
                break ;

        }

    }
}
