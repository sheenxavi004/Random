#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head=NULL;
void push()
{
    int num;
    printf("\nEnter number to insert");
    scanf("%d",&num);
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->link=head;
        head=new;
    }
}
void pop()
{
    if(head==NULL)
        printf("\nEMPTY!DELETION NOT POSSIBLE");
    else
    {
        struct node* tmp=head;
        printf("\nPOPPED ITEM IS %d",tmp->data);
        head=head->link;
        free(tmp);
    }
}
void display()
{
    if(head==NULL)
        printf("\nEMPTY !!");
    else
    {
        printf("\n");
        struct node *tmp=head;
        while(tmp!=NULL)
        {
            printf("%d  ",tmp->data);
            tmp=tmp->link;
        }
    }
    
}
int main()
{
    int choice;
    printf("\n------------STACK OPERATIONS USING LINKED LIST---------------");
     while(1)
    {
    printf("\nMENU");
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
    scanf("%d",&choice);
    switch(choice)
    {
   	 case 1:push();
   		 break;
   	 case 2:pop();
   		 break;
   	 case 3:display();
   		 break;
   	 case 4:return 0;
   	 default:printf("\nWrong choice");
    }
    }
    return 0;
}

