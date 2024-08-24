#include<stdio.h>
struct array
{
    int activity_no;
    int s_t;
    int f_t;

};
int main()
{
    int i,j;
    struct array arr[10];
    for(i=0;i<10;i++)
    {
        scanf("%d %d",&arr[i].s_t,&arr[i].f_t);
    }
    for(i=0;i<10;i++)
    {
        arr[i].activity_no=i+1;
    }
    struct array temp;
    for(i=0;i<10;i++)
    {
        for(j=0;j<9;j++)
        {   if(arr[j+1].f_t<arr[j].f_t)
          {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
          }
        }
    }
    int st=-1;
    for(i=0;i<10;i++)
    {
        if(arr[i].s_t >= st)
        {
            st=arr[i].f_t;
            printf("%d\t",arr[i].activity_no);
        }
    }
    
}