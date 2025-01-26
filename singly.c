#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *addr;
};
struct node *head=NULL;
int notExit=1;

struct node *createnode(int item);
int node_count();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void display_list();

struct node *createnode(int item)
{
struct node *nn;
nn=(struct node*)malloc(sizeof(struct node));
nn->data=item;
return nn;
}
int node_count()
{
int count=0;
struct node *temp=head;
while(temp!=NULL)
{
count=count+1;
temp=temp->addr;
}
return count;
}

void insert_beg()
{
int item;
struct node *nn;
printf("Enter the element:");
scanf("%d",&item);
nn=createnode(item);
if(head==NULL){
nn->addr=NULL;
head=nn;
}
else
{
nn->addr=head;
head=nn;
}
display_list();
}

void insert_end()
{
int item;
struct node *nn;
printf("Enter the element:");
scanf("%d",&item);
nn=createnode(item);
if(head==NULL)
{
nn->addr=NULL;
head=nn;
}
else{
struct node *p=head;
while(p->addr!=NULL)
{
p=p->addr;
}
p->addr=nn;
nn->addr=NULL;
}
display_list();
}

void insert_pos()
{
int item,pos,count;
printf("Enter the position to which element is to be inserted:");
scanf("%d",&pos);
count=node_count();
if(pos>count)
{
printf("Enter a valid position!\n");
}
else{
printf("\nEnter the element:");
scanf("%d",&item);
struct node *nn;
nn=createnode(item);
if(head==NULL)
{
nn->addr=NULL;
head=nn;
}
else
{
struct node *p=head;
for(int i=1;i<pos-1;i++)
{
p=p->addr;
}
nn->addr=p->addr;
p->addr=nn;
}
display_list();
}
}

void delete_beg()
{
if(head==NULL)
{
printf("Linked list is Empty!");
}
else
{
struct node *p=head;
p=p->addr;
head=p;
}
display_list();
}

void delete_end()
{
if(head==NULL)
{
printf("Linked list is Empty!");
}
else{
struct node *p=head,*c=head;
while(p->addr!=NULL)
{
c=p;
p=p->addr;
}
c->addr=NULL;
}
display_list();
}

void delete_pos()
{
int pos,count;
printf("Enter the position from which element is to be deleted:");
scanf("%d",&pos);
count=node_count();
if(pos>count)
{
printf("Enter a valid position!\n");
}
else
{
if(head==NULL)
{
printf("Linked list is Empty!");
}
else
{
struct node *p=head,*c=head;
for(int i=1;i<pos;i++)
{
c=p;
p=p->addr;
}
c->addr=p->addr;
}
display_list();
}
}

void display_list()
{
if(head==NULL)
{
printf("Linked list is empty!");
}
else
{
struct node *p=head;
printf("Linked list:");
while(p->addr!=NULL)
{
printf("%d",p->data);
p=p->addr;
}
printf("%d\n",p->data);
}
}

void main()
{
int opt;
while(notExit==1)
{
printf("\n1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Display Linkedlist\n8.Exit.");
printf("\nEnter the operator:");
scanf("%d",&opt);

switch(opt)
{
case 1:
insert_beg();
break;
case 2:
insert_end();
break;
case 3:
insert_pos();
break;
case 4:
delete_beg();
break;
case 5:
delete_end();
break;
case 6:
delete_pos();
break;
case 7:
display_list();
break;
case 8:
notExit=0;
printf("Exited!\n");
break;
default:
printf("Enter a valid operator!");
}
}
}
