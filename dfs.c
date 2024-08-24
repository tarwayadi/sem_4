#include<stdio.h>
const int v=6;
void dfs(int node,int vis[],int m[v][v])
{
    vis[node]=1;
    printf("%d\t",node);
    for(int i=0;i<6;i++)
    {
        if(m[node][i]==1)
        {
            if(vis[i]==0)
            dfs(i,vis,m);
        }
    }


}
int main()
{
   int m[6][6]={{0,1,1,0,0,0},
                  {1,0,0,1,1,0},
                  {1,0,0,0,0,0},
                  {0,1,0,0,0,1},
                  {0,1,0,0,0,0},
                  {0,0,0,1,0,0}}; 
    int vis[6]={0};
    dfs(0,vis,m);              
}