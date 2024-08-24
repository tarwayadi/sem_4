#include<stdio.h>
int max(int a,int b)
{
    if(a>=b)
    return a;
    else
    return b;
}
int main()
{   int bag_c=10,nontake,take;
    int o=4;
    int wt[]={0,1,3,4,6};
    int pf[]={0,20,30,10,50};
    int m[o+1][bag_c+1];
    for(int i=0;i<=o;i++)
    {
        for(int j=0;j<=bag_c;j++)
        {
            if(i==0||j==0)
            {
                m[i][j]=0;
            }
            else{
                nontake=m[i-1][j];
                if(j-wt[i]>=0){
                take=pf[i]+m[i-1][j-wt[i]];
                }
                else{
                    take=-99999;
                    }
                m[i][j]=max(take,nontake);
            }
        }
    }
    for(int i=0;i<=o;i++)
    {
        for(int j=0;j<=bag_c;j++)
        {  
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("maximum profit is:%d",m[o][bag_c]);
}