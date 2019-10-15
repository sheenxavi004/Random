#include<stdio.h>
#include<stdlib.h>
struct node
{       
    int data;
    struct node *link;
}*head=NULL;
void insert_at_head();
void delete_at_head();
void insert_at_tail();
void delete_at_tail();
void insert_at_position();
void delete_at_position();
void insert_before();
void delete_before();
void display();
int main()
{
    int choice;
    while(1)
    {
    printf("\nMENU:\n1.INSERTION AT HEAD\n2.DELETION AT HEAD\n3.INSERTION AT TAIL\n4.DELETION AT TAIL\n5.INSERTION AT POSITION\n6.DELETION AT POSITION\n7.INSERTION BEFORE DATA\n8.DELETION BEFORE DATA\n9.DISPLAY\n10.EXIT");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert_at_head();
                break;
        case 2:delete_at_head();
                break;
        case 3:insert_at_tail();
                break;
        case 4:delete_at_tail();
            break;
        case 5:insert_at_position();
            break;
        case 6:delete_at_position();
            break;
        case 7:insert_before();
            break;
        case 8:delete_before();
            break;
        case 9:display();
                break;
        case 10:return 0;
        default:printf("\nWrong choice");
    }
    }
    return 0;
}
int length()
{
    int num=0;
    struct node* tmp=head;
    while(tmp!=NULL)
    {
        num++;
        tmp=tmp->link;
    }
    return num;
}
void insert_at_head()
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
void delete_at_head()
{
    if(head==NULL)
        printf("\nEMPTY!DELETION NOT POSSIBLE");
    else
    {
        struct node* tmp=head;
        printf("\nDELETED ITEM IS %d",tmp->data);
        head=head->link;
        free(tmp);
    }
}
void insert_at_tail()
{   
    int num;
    printf("\nENTER DATA TO INSERT");
    scanf("%d",&num);
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=num;
    tmp->link=NULL;
    if(head==NULL)
    {
        head=tmp;
    }
    else
    {
        struct node* p=(struct node*)malloc(sizeof(struct node));
        p=head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=tmp;
    }
}
void delete_at_tail()
{
    if(head==NULL)
    {
        printf("\nEMPTY!DELETION NOT POSSIBLE");
    }
    else
    {
        struct node* tmp,*prev;
        tmp=head;
        prev=head;
        while(tmp->link!=NULL)
         {   prev=tmp;
             tmp=tmp->link;

         }
         printf("\nDELETED ITEM IS %d",tmp->data);
         if(prev->link==NULL)
            head=NULL;
        else
            prev->link=NULL;
         

    }
}
//what if pos more than length
void insert_at_position()
{
    int pos,dat;
    int len=length();
    printf("\nENTER POSITION");
    scanf("%d",&pos);
    struct node* tmp;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    tmp=head;
    printf("\nENTER DATA");
    scanf("%d",&dat);
    new->data=dat;
    new->link=NULL;
    if(pos==1)
    {
        new->link=head;
        head=new;
    }
    else if(pos>len)
    {
        printf("\nONLY %d ELEMENTS IN LINKED LIST!!!",len);
        return;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            tmp=tmp->link;
        }
        new->link=tmp->link;
        tmp->link=new;
    }
}
//what if pos more than length or if empty
void delete_at_position()
{
    int pos;
    int len=length();
    if(head==NULL)
    {
        printf("\nEMPTY!!DELETION NOT POSSIBLE");
        return;
    }
    printf("\nEnter position");
    scanf("%d",&pos);
    if(pos>len)
    {
        printf("\nONLY %d ELEMENTS IN LINKED LIST!!!",len);
        return;
    }
    struct node*tmp=head,*prev=head;
    if(pos==1)
    {
        head=head->link;
    }
    else
    {
        for(int i=1;i<pos;i++)
         {   prev=tmp;
             tmp=tmp->link;
         }
         printf("\nDELETED ITEM IS %d",tmp->data);
         prev->link=tmp->link;

    }
    
}
void insert_before()
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    struct node* tmp,*prev;
    int data,num;
    printf("\nENTER DATA BEFORE WHICH INSERTION IS GOING TO HAPPEN");
    scanf("%d",&data);
    printf("\nENTER DATA");
    scanf("%d",&num);
    new->data=num;
    new->link=NULL;
    tmp=head;
    prev=NULL;
    if(data==head->data)
    {
        new->link=head;
        head=new;
        return;
    }
    while(data!=tmp->data)
    {
        prev=tmp;
        if(tmp->link==NULL)
        {
        printf("\nELEMENT NOT FOUND!!!");
        return;
        }
        tmp=tmp->link;
    }

    new->link=prev->link;
    prev->link=new;

}
void delete_before()
{
    int del,flag=0;
    struct node *p =head;
    struct node *tmp=head,*prev=head,*preprev=head;
    printf("\nENTER ELEMENT BEFORE WHICH U WANT TO DELETE");
    scanf("%d",&del);
    if(head->data==del)
    {
        printf("\nNO ELEMENT BEFORE DATA!!NO DELETION POSSIBLE");
        return;
    }
    int num=p->data;
    p=p->link;
    if(p->data==del)
    {
        head=p;
        printf("\nDELETED ELEMENT IS %d",num);
        return;
    }
    while(tmp->data!=del)
    {
        preprev=prev;
        prev=tmp;
        if(tmp->link==NULL)
        {
        printf("\nELEMENT NOT FOUND!!!");
        return;
        }
        tmp=tmp->link;
    }
        printf("\nDELETED ELEMENT IS %d",prev->data);
        preprev->link=prev->link;

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
