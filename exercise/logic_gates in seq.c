#include <stdio.h>
#include <stdlib.h>

/*LOGIC GATES IN SEQUENCE */

void main()
{
    int  ans;
    int n = 3;
    int arr[n];
    int in1,in2;
    while(1)
    {
        printf("1.AND\n2.OR\n3.NOT\n") ;
        for(int i=0;i<n;i++)
        {
            printf("Enter operation no. in sequence:\n",i+1) ;
            scanf(" %d",&arr[i]);
        }
        ans= -1;
        for(int i=0;i<3;i++)
        {
            switch(arr[i])
            {
                case 1 : if(ans<0){
                            printf("Enter two inputs :- ");
                            scanf("%d %d",&in1,&in2);
                            ans=AND(in1,in2);
                            }
                        else{
                            printf("Enter one inputs :- ");
                            scanf("%d",&in2);
                            ans = AND(ans,in2);
                        }
                        break;
                case 2 :
                    if(ans<0)
                        {
                            printf("Enter two inputs :- ");
                            scanf("%d %d",&in1,&in2);
                            ans=OR(in1,in2);
                        }
                        else{
                            printf("Enter one inputs :- ");
                            scanf("%d",&in2);
                            ans=OR(ans,in2);
                        }break;
                case 3 :
                    if(ans<0)
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
