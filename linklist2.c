#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node* createnode(int data)
{  
    struct node *temp=(struct node*)malloc(sizeof(struct node));
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
    else if(head->next==NULL)
    {
        head->next=ptr;
    }
    else
    {
        struct node* run;
        run=head;
        while(run->next!=NULL)
        {
            run=run->next;
        }
        run->next=ptr;
    }
}
    void display()
    {
        struct node* ptr=head;
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            printf("\n");
            ptr = ptr->next;
        }
        printf("\n");
    }
   void deletenode(int data)
   {
     struct node*run;
     run=head;
     while(run->next->data!=data)
     {
        run=run->next;
     }
     if(run->next->data==data)
     {  struct node* ptr=run->next;
        run->next=run->next->next;
        free(ptr);
     }
   } 


int main()
{
    insertnode(69);
    insertnode(5);
    insertnode(6);
    insertnode(8);
    insertnode(7);
    display();
    printf("\n");
    deletenode(6);
    display();
    
}