#include<stdio.h>
int n,front=-1,rear=-1,queue[20];
int notExit=1;

void enqueue()
{
if(rear==n-1)
printf("Queue Overflow\n");
else
{
printf("Enter item to enqueue:");
int item;
scanf("%d",&item);
if((front==-1)&&(rear==-1))
{
front=rear=0;
queue[rear]=item;
}
else
{
rear++;
int i=rear-1;
while((i>=0)&&(queue[i]>item))
{
queue[i+1]=queue[i];
i--;
}
queue[i+1]=item;
}
}
}

void dequeue()
{
if((front==-1)&&(rear==-1))
printf("Queue is empty\n");
else
{
printf("dequeue item is:%d\n",queue[front]);
if(front==rear)
rear=front=-1;
else
front++;
}
}

void display()
{
int i;
if((front==-1)&&(rear==-1))
printf("Queue is empty\n");
else
{
for(i=front;i<=rear;i++)
printf("%d\t",queue[i]);
printf("\n");
}
}

int main()
{
printf("Enter the size of queue;\n");
scanf("%d",&n);
while(notExit==1)
{
int choice;
printf("\n1:ENQUEUE\t2.DEQUEUE\t3.DISPLAY\t4.EXIT\n");
printf("Enter your choice:");
scanf("%d",&choice);

switch(choice)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
printf("Queue exit!\n");
break;
default:
printf("invaild choice\n");
}
}
}

