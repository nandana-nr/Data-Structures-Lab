#include <stdio.h>
int dequeue[100], front = -1, rear = -1, maxsize;

void insert_front() 
{
int item;
printf("Enter the item to be inserted at the front of the queue: ");
scanf("%d", &item);

if ((front == 0 && rear == maxsize - 1) || (front == rear + 1)) 
{
printf("Queue Overflow\n");
} 
else if (front == -1) 
{
front = rear = 0;
dequeue[front] = item;
} 
else if (front == 0) 
{
front = maxsize - 1;
dequeue[front] = item;
} 
else 
{
front--;
dequeue[front] = item;
}
printf("%d item is inserted at the front of the queue\n", item);
}

void insert_rear() 
{
int item;
printf("Enter the item to be inserted at the rear of the queue: ");
scanf("%d", &item);

if ((front == 0 && rear == maxsize - 1) || (front == rear + 1)) 
{
printf("Queue Overflow\n");
} 
else if (rear == -1) 
{
front = rear = 0;
dequeue[rear] = item;
}
 else if (rear == maxsize - 1) 
 {
rear = 0;
dequeue[rear] = item;
} 
else 
{
rear++;
dequeue[rear] = item;
}
printf("%d is inserted at the rear of the queue\n", item);
}

void delete_front() 
{
if (front == -1) 
{
printf("Queue Underflow\n");
} 
else 
{
int item = dequeue[front];
printf("Item dequeued from the front: %d\n", item);

if (front == rear) 
{
front = rear = -1; 
} 
else if (front == maxsize - 1) 
{
front = 0;
} 
else {
front++;
}
}
}

void delete_rear() 
{
if (rear == -1) 
{
printf("Queue Underflow\n");
} 
else 
{
int item = dequeue[rear];
printf("Item dequeued from the rear: %d\n", item);

if (front == rear) 
{
front = rear = -1;  
} 
else if (rear == 0) 
{
rear = maxsize - 1;
} 
else 
{
rear--;
}
}
}

void display() 
{
if (front == -1) 
{
printf("Queue is Empty\n");
} 
else 
{
printf("Queue elements are: ");
int i = front;
while (1) 
{
printf("%d ", dequeue[i]);
if (i == rear) 
{
break;
}
i = (i + 1) % maxsize;
}
printf("\n");
}
}

int main() 
{
int choice, item;
printf("Enter the maximum size of the queue: ");
scanf("%d", &maxsize);

while (1) 
{
printf("\n----Queue Operations----\n");
printf("1. Insert Front\n");
printf("2. Insert Rear\n");
printf("3. Delete Front\n");
printf("4. Delete Rear\n");
printf("5. Display\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) 
{
case 1:
insert_front();
break;
case 2:
insert_rear();
break;
case 3:
delete_front();
break;
case 4:
delete_rear();
break;
case 5:
display();
break;
case 6:
return 0;
default:
printf("Invalid Choice\n");
}
}
return 0;
}




