#include<stdio.h>
int min(int a,int b)
{
    if(a>=b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int main()
{
    int a[5]={5,4,6,2,7};
    int m[5][5];
    int r,c,prev_col=0,val;
    

    while(prev_col<5)
    {
        r=1;
        c=1+prev_col;
        while(r<5 && c<5)
        {
            if(r==c)
            {
                m[r][c]=0;
            }
            else

            {    int ans=999999;
                  for(int i=r;i<c;i++)
            {
                 val=m[r][i]+m[i+1][c]+ (a[r-1]*a[i]*a[c]);
                 ans=min(val,ans);
            }
            m[r][c]=ans;
                
            }
            r++;
            c++;
        }
        prev_col++;

    }
    printf("\n minimum operation for matrix is:%d",m[1][4]);
}