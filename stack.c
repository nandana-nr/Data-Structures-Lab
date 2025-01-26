#include<stdio.h>
int stack[50],maxsize,top=-1;
void push(int item)
{
int i;
for(i=0;i<maxsize;i++)
{
if(top>=maxsize-1)
{
printf("stack overflow");
}
else
{
printf("Enter the element:");
scanf("%d",&item);
top++;
stack[top]=item;
}
}
}
int pop(int item)
{
if(top==-1)
{
printf("stack underflow");
}
else{
item=stack[top];
top--;
}
}
void display()
{
int i;
if(top==-1)
{
printf("empty stack");
}
else
{
printf("Stack element is:");
for(i=top;i>=0;i--)
{
printf("%d",stack[i]);
}
}
}
int main()
{
int c, item;
printf("Enter the maxsize of stack:");
scanf("%d",&maxsize);
while(1)
{
printf("Select the operations: \n1:Push\t2:Pop\t3:Display\t4:Exit\n");
scanf("%d",&c);
switch(c)
{
case 1:
push(item);
break;
case 2:
pop(item);
break;
case 3:
display(item);
break;
case 4:
return 0;
break;
default:
printf("wrong choice");
break;
}
}
}

