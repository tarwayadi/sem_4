#include<stdio.h>
int i,n,elem,a[100];
int binary(int x)
{
    int st=0,mid;
    int end=n-1;
    while(st<=end)
    {
        mid=(st+end)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        else if(x<a[mid])
        {
          end=mid-1;
        }
        else if(x>a[mid])
        {  
          st=mid+1;
        }
    }
}
int main()
{
    int ans,elem;
    printf("enter the size of array\n");
    scanf("%d",&n);
    
    printf("enter the element \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("insert element to be searched: ");
    scanf("%d",&elem);
    ans=binary(elem);
    printf("the position is %d",ans);
    return 0;
}
