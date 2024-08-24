#include<stdio.h>
#include<stdlib.h>
struct node
{
    int dis;
    int NODE;
    struct node*next;

};
struct node*head=NULL;
struct node*createnode(int dis,int NODE)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->dis=dis;
    temp->NODE=NODE;
    temp->next=NULL;

    return temp;
}
void insertnode(int dis,int NODE)
{
    struct node*ptr=createnode(dis,NODE);
    if(head==NULL)
    {
        head=ptr;
    }
    else if(head->next==NULL)
    {
        if(head->dis<ptr->dis)
        {
           head->next=ptr;
        }
        else
        {
            ptr->next=head;
            head=ptr;

        }
    }
    else{
        struct node*run;
        run=head;
        if(ptr->dis<head->dis)
        {
            ptr->next=head;
            head=ptr;
        }
        else{
            while(run->next!=NULL && run->next->dis<ptr->dis)
            {
                run=run->next;
            }
            ptr->next=run->next;
            run->next=ptr;
        }
        

    }
}
void display()
{
    struct node*ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->dis);
        printf("\t");
        ptr=ptr->next;
    }
}
void pop()
{
       struct node*temp;
    temp=head;
    head=head->next;
    free(temp);
}
int main()
{
    int m[9][9]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int d[9];
    for(int i=0;i<9;i++)
    {
        d[i]=1e9;
    }
    d[0]=0;
    insertnode(0,0);
    while(head!=NULL)
    {
        int di=head->dis;
        int N=head->NODE;
        pop();
        
        for(int i=0;i<9;i++)
        {
            if(m[N][i]>0)
            {
                if(di+m[N][i]<d[i])
                {
                    d[i]=m[N][i]+di;
                    insertnode(m[N][i]+di,i);
                }
            }
            
        }
        

    }
    for(int i=0;i<9;i++)
    {
    printf("%d\t",d[i]);
    }

    

}