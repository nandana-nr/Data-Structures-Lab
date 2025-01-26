#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxsize 100
char stack[maxsize];
int top=-1;

void push(char item)
{
if (top>=maxsize-1)
{
printf("Stack Overflow\n");
}
else
{
stack[++top]=item;
}
}
char pop()
{
if(top<0)
{
printf("Stack Underflow\n");
return -1;
}
else
{
return stack[top--];
}
}

int precedence(char symbol)
{
switch (symbol)
{
case'+':
case'-':
return 1;
case'*':
case'/':
return 2;
case'^':
return 3;
default:
return 0;
}
}

int isOperator(char symbol)
{
return (symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^');
}

int infixtopostfix(char infix[], char postfix[])
{
int i,j=0;
char item, temp;
for(i=0;i<strlen(infix);i++)
{
if(isalnum(infix[i]))
{
postfix[j++]=infix[i];
}
else if (infix[i]=='(')
{
push(infix[i]);
}
else if(infix[i]==')')
{
while(top!=-1&&stack[top]!='(')
{
postfix[j++]=pop();
}
if(top!=-1)
pop();
}
else
{
while(top!=-1 && stack[top]!='(' && precedence(stack[top])>=precedence(infix[i]))
{
postfix[j++]=pop();
}
push(infix[i]);
}
}
while(top!=-1)
{
postfix[j++]=pop();
}
}

int main()
{
char infix[maxsize],postfix[maxsize];
printf("Enter an infix expression :");
scanf("%s",infix);
infixtopostfix(infix,postfix);
printf("Postfix expression:%s\n",postfix);
return 0;
}


