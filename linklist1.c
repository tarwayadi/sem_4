#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* createnode(int data)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    return temp;
}
void insertnode(int data)
{
    struct node* ptr=createnode(data);
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
}
void display()
{   struct node*ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        printf("\t");
        ptr=ptr->next;

    }

}
int main()
{
    insertnode(5);
    insertnode(6);
    insertnode(7);
    insertnode(8);
    display();
} 