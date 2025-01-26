#include<stdio.h>
int queue[100];
int front=-1;
int rear=-1;
int size;
int notExit =1;

void enqueue(int item)
{
if(front==-1 && rear==-1)
{
front=rear=0;
queue[rear]=item;
}
else if(((rear+1)%size)==front)
{
printf("Queue overflow\n");
}
else
{
rear=(rear+1)%size;
queue[rear]=item;
}
}

void dequeue()
{
if(front==-1 && rear==-1)
{
printf("\nQueue is empty\n");
}
else if(front==rear)
{
printf("\n Deleted item is : %d\n",queue[front]);
front=rear=-1;
}
else
{
printf("\n Deleted item is : %d\n",queue[front]);
front=(front+1)%size;
}
}

void display()
{
if(front==-1 && rear==-1)
{
printf("Queue is empty\n");
}
else
{
printf("Queue is:");
for(int i=front;i!=rear;i=(i+1)%size)
{
printf("%d",queue[i]);
}
printf("%d\n",queue[rear]);
}
}

void main()
{
printf("Enter the size of queue:");
scanf("%d",&size);

while (notExit==1)
{
int choice,item;

printf("\n1:INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT\n");
printf("Enter your choice:");
scanf("%d",&choice);

switch (choice)
{
case 1:
printf("Enter the element to insert:");
scanf("%d",&item);
enqueue(item);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
notExit=0;
printf("\nExited\n");
break;
default:
printf("Invalid choice\n");
}
}
}

