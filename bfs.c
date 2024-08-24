#include<stdio.h>


int f=-1;
int r=-1;
void push(int data,int q[])
{
    if(f==-1 && r==-1)
    {
        f++;
        r++;
        q[r]=data;
    }
    else{
        r++;
        q[r]=data;
    }
}
void pop()
{
    f++;
}
int main()
{
    int mat[6][6]={{0,1,1,0,0,0},
                   {0,0,0,1,1,0},
                   {1,0,0,0,0,0},
                   {0,0,0,0,0,1},
                   {0,1,0,0,0,0},
                   {0,0,0,1,0,0}};
   int vis[6]={0};
   int q[100];
   push(0,q);
   while(f<=r)
   {
     int node=q[f];
     pop();
     vis[node]=1;
     printf("%d\t",node);
     for(int i=0;i<6;i++)
     {
        if(mat[node][i]==1)
        {
            if(vis[i]==0)
            push(i,q);
        }
     }
   }
                   
}