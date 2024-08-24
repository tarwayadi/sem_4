#include<stdio.h>
int main()
{
    int mx=99999;
    int ver=4;
    int m[4][4]={{0,mx,mx,mx},
                  {4,0,-6,mx},
                  {mx,mx,0,5},
                  {mx,-2,mx,0}};
    int dis[ver];
    for(int i=0;i<ver;i++)
    {
        dis[i]=1e9;
    }
    for(int t=1;t<=ver-1;t++)
    {
        for(int i=0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(i!=j&& m[i][j]!=mx){
                    if(dis[i]+m[i][j]<dis[j])
                    {
                       dis[j]=dis[i]+m[i][j]; 
                    }
                }
            }
        }
    }
    int f=1;
    for(int i=0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(i!=j&& m[i][j]!=mx){
                    if(dis[i]+m[i][j]<dis[j])
                    {
                       
                       printf("-ve weight cycle present");
                       f=0;
                       break; 
                    }
                }
                
            }
            if(f==0)
            break;
        }
        

}