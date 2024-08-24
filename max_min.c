#include<stdio.h>
#define MAX_SIZE 100
int maximum(int array[],int index,int len)
{
    int max;
    if(index>=len-2)
    {
        if(array[index]>array[index+1])
         {
            return array[index];
         }
         else
         {
            return array[index+1];
        }
    }
    max=maximum(array,index+1,len);
    if(array[index]>max)
    {
        return array[index];
    }
    else
    {
        return max;
    }
}
int minimum(int array[],int index,int len)
{
    int min;
    if(index>=len-2)
    {
        if(array[index]<array[index+1])
         {
            return array[index];
         }
         else
         {
            return array[index+1];
        }
    }
    min=minimum(array,index+1,len);
    if(array[index]<min)
    {
        return array[index];
    }
    else
    {
        return min;
    }
}
int main()
{
    int array[MAX_SIZE],n,max,min;
    int i;
    printf("enter the size of an array");
    scanf("%d",&n);
    printf("enter %d elements in array:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    max=maximum(array,0,n);
    min=minimum(array,0,n);
    printf("maximum element=%d\n",max);
    printf("minimum element=%d\n",min);
    

}
