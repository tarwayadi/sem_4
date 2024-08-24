#include<stdio.h>
struct array
{

    int deadline;
    int profit;
};

int maximum( int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    struct array arr[5];
    int i,j;

    for(i=0;i<5;i++)
    {
        scanf("%d %d",&arr[i].profit,&arr[i].deadline);
    }

    struct array temp;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[j+1].profit < arr[j].profit)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

int max;

max=arr[0].profit;

for(i=1;i<5;i++)
{
        max=maximum(max,arr[i].deadline);
}
//printf("%d",max);
int seq_job[3]={0};
for(i=4;i>=0;i--)
{
    if(seq_job[arr[i].deadline-1]==0)
    {
        seq_job[arr[i].deadline-1]=arr[i].profit;
    }
    else
    {
        j=arr[i].deadline-1;
        while(j>=0)
        {
            if(seq_job[j]==0)
            {
                seq_job[j]=arr[i].profit;
                break;
            }
            j--;
        }
        
    }
}
for(i=0;i<3;i++)
{
    printf("%d",seq_job[i]);
}

}