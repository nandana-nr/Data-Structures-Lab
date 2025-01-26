#include<stdio.h>
int queue[100];
int front=0;
int rear=-1;
int size;
int notExit =1;

void enqueue(int item)
{
if(rear>=size-1)
{
printf("Queue Overflow\n");
}
else
{
rear=rear+1;
queue[rear]=item;
printf("%d enqueued to queue \n",item);
}
}


int dequeue()
{
if(front>rear)
{
printf("Queue underflow\n");
return -1;
}
else
{
int item=queue[front];
front=front+1;
return item;
}
}


void display()
{
if(front>rear)
{
printf("Queue is empty\n");
}
else
{
printf("Queue elements are:");
for(int i=front;i<=rear;i++)
{
printf("%d",queue[i]);
}
printf("\n");
}
}

int main()
{
printf("Enter the size of queue:");
scanf("%d",&size);

int choice,item;

printf("\n1:ENQUEUE\t2.DEQUEUE\t3.DISPLAY\t4.EXIT\n");
while(notExit)
{
printf("Enter your choice:");
scanf("%d",&choice);

switch (choice)
{
case 1:
printf("Enter the item to enqueue:");
scanf("%d",&item);
enqueue(item);
break;
case 2:
item=dequeue();
if(item!=-1)
{
printf("%d dequeued from queue\n",item);
}
break;
case 3:
display();
break;
case 4:
notExit=0;
break;
default:
printf("Invalid choice\n");
break;
}
}
return 0;
}









