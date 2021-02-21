
#include <stdio.h>
#include <conio.h>




void main()
{
    int  ch ;
   int n=3;
    char arr[n];
    int in1,in2;
    while(1)
    {
        for(int i=0;i<n;i++)
        {
           printf("Select one option :-\n1)AND\n2.OR\n3.NOT\n");
           scanf("%d",&ch);
           switch(ch)
           {

           case 1:arr[i]="&";
                    break;
            case 2:arr[i]="|";
                    break;
            case 3:arr[i]="!";
                    break;
           }
        //   scanf("%c",&arr[i]);

        }

        int ans=-1;
        for(int i=0;i<3;i++)
        {
            switch(arr[i])
            {
                case '&': if(ans<0){
                            printf("Enter two inputs :- ");
                            scanf("%d %d",&in1,&in2);
                            ans=AND(in1,in2);
                            }
                    else{
                         printf("Enter one inputs :- ");
                        scanf("%d",&in2);
                        ans=AND(ans,in2);
                        }
                        break;
            case '|':if(ans<0){
                        printf("Enter two inputs :- ");
                        scanf("%d %d",&in1,&in2);
                        ans=OR(in1,in2);
                    }
                    else{
                         printf("Enter one inputs :- ");
                        scanf("%d",&in2);
                        ans=OR(ans,in2);
                        }break;
            case '!': if(ans<0)
                        {
                        printf("Enter one inputs :- ");
                        scanf("%d",&in2);
                        ans=NOT(in2);
                        }
                    else
                        {
                        ans=NOT(ans);
                        }
            }
        }
        printf("Result = %d\n",ans);
        ans=-1;
       // printf("hui\n") ;
    }
}

int AND(int a,int b)
{

    if(a == 1 && b == 1)
        return 1 ;
    else
        return 0 ;

}
int OR(int a,int b)
{

    if(a == 1 || b == 1)
        return 1 ;
    else
        return 0 ;
}

int NOT(int a)
{

    if(a)
        return 0 ;
    else
        return 1 ;
}
