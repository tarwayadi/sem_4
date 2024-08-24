#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;

};
struct node*head=NULL;
struct node*createnode(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    return temp;
}
void insertnode(int data)
{
    struct node*ptr=createnode(data);
    if(head==NULL)
    {
        head=ptr;
    }
    else if(head->next==NULL)
    {
        if(head->data<ptr->data)
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
        if(ptr->data<head->data)
        {
            ptr->next=head;
            head=ptr;
        }
        else{
            while(run->next!=NULL && run->next->data<ptr->data)
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
        printf("%d",ptr->data);
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
    insertnode(2);
    insertnode(4);
    insertnode(-1);
    insertnode(6);
    insertnode(8);
    insertnode(-10);
    insertnode(20);
    display();
    pop();
    printf("\n");
    display();
    
}