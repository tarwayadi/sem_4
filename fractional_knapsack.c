#include<stdio.h>
struct array
{
    float weight;
    float profit;
    float ratio;

};
int main()
{   int i,j;
    struct array arr[7];
    float capacity,totalvalue;
    for(i=0;i<7;i++)
    {
         scanf("%f %f",&arr[i].weight,&arr[i].profit);
    }
    
    scanf("%f",&capacity);
    for(i=0;i<7;i++)
    {
        arr[i].ratio=arr[i].profit/arr[i].weight;
    }
    struct array temp;
    for(i=0;i<7;i++)
    {
        for(j=0;j<6;j++)
        {
            if(arr[j+1].ratio<arr[j].ratio)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }

    }
    
    for(i=6;i>0;i--)
    {
        if(capacity-arr[i].weight>=0)
        {
            capacity=capacity-arr[i].weight;
            totalvalue=totalvalue + arr[i].profit;
        }
        else
        {   totalvalue=totalvalue + (arr[i].ratio*capacity);
            break;
        }
    }
    
    
        
        printf("\n the maximum value is:%f\n",totalvalue);
        return 0;
    


}