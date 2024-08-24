#include<stdio.h>
int main()
{   int mx=99999;
    int ver=9;
    int m[9][9]={       { 0, 4, mx, mx, mx, mx, mx, 8, mx },
                        { 4, 0, 8, mx, mx, mx, mx, 11, mx },
                        { mx, 8, 0, 7, mx, 4, mx, mx, 2 },
                        { mx, mx, 7, 0, 9, 14, mx, mx, mx },
                        { mx, mx, mx, 9, 0, 10, mx, mx, mx },
                        { mx, mx, 4, 14, 10, 0, 2, mx, mx},
                        { mx, mx, mx, mx, mx, 2, 0, 1, 6 },
                        { 8, 11, mx, mx, mx, mx, 1, 0, 7 },
                        { mx, mx, 2, mx, mx, mx, 6, 7, 0 } };
    int dis[ver];
    
    for(int i=0;i<ver;i++)
    {
        dis[i]=1e9;
    }
    dis[0]=0;
    for(int time=0;time<ver-1;time++)
    {
        for(int i=0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(i!=j && m[i][j]!=mx)
                {
                    if(dis[i]+m[i][j]<dis[j])
                    {
                        dis[j]=dis[i]+m[i][j];
                    }
                }
            }
        }
    }

    int flag=1;
    for(int i=0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(i!=j && m[i][j]!=mx)
                {
                    if(dis[i]+m[i][j]<dis[j])
                    {
                        printf("given graph has negative weight cycle");
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==0)
            break;
        }


printf("minimum distance array at last stage is:\n");   
for(int i=0;i<ver;i++)
     {   
        printf(" %d\t",dis[i]);
     }   


}