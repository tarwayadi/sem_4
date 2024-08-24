#include<stdio.h>
#include<stdlib.h>
struct node
{
    int wt;
    int NODE;
    struct node*next;

};
struct node*head=NULL;
struct node*createnode(int wt,int NODE)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp-> wt=wt;
    temp->NODE=NODE;
    temp->next=NULL;

    return temp;
}
void insertnode(int wt,int NODE)
{
    struct node*ptr=createnode(wt,NODE);
    if(head==NULL)
    {
        head=ptr;
    }
    else if(head->next==NULL)
    {
        if(head->wt<ptr->wt)
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
        if(ptr->wt<head->wt)
        {
            ptr->next=head;
            head=ptr;
        }
        else{
            while(run->next!=NULL && run->next->wt<ptr->wt)
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
        printf("%d",ptr->wt);
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
    int m[6][6] = { { 0, 4, 0, 0, 0,2 },
                        { 4, 0, 6, 0, 0,3 },
                        { 0, 6, 0, 3,0, 1 },
                        { 0, 0, 3, 0, 2,0 },
                        {0,0,0,2,0,4},
                        {2,3,1,0,4,0} };
    int v[6]={0};
    insertnode(0,0);
    int sum=0;
    while(head!=NULL)
    {
        int w=head->wt;
        int N=head->NODE;
        pop();
        if(v[N]==0)
        {
            sum =sum+w;
            v[N]=1;

        }
        for(int i=0;i<6;i++)
        {
            if(v[i]==0 && m[N][i]>0)
            insertnode(m[N][i],i);
        }
        

    }
    printf("%d",sum);

}