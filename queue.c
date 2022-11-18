#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * f=NULL;
struct node * r=NULL;
void traversal(struct node * head)
{
    struct node * ptr =head;
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}
void enqueue(int data)
{
    struct  node *ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("queue is full");
    }
    else
    {
        ptr->data=data;
        ptr->next=NULL;
        if(f==NULL)
        {
            f=r=ptr;
        }
        else
        {
            r->next=ptr;
            r=ptr;
        }
    }
    
}
int denqueue()
{
    int val=-1;
    struct node *ptr=f;
    if(f==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    enqueue(35);
    enqueue(40);
    enqueue(56);
    enqueue(55);
    enqueue(78);
    enqueue(9);
    traversal(f);
    denqueue();
    traversal(f);

}