#include<stdio.h>
#include<stdlib.h>
struct node
{
int coeff,expo;
struct node*next;
};
struct node*createnode(int coeff,int expo)
{
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->coeff=coeff;
newnode->expo=expo;
newnode->next=NULL;
return newnode;
}
void addnode(struct node**poly,int coeff,int expo)
{
struct node*newnode=createnode(coeff,expo);
if(*poly==NULL)
{
*poly=newnode;
}
else
{
struct node*temp=*poly;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
}
void displaypolynomial(struct node*poly)
{
while(poly!=NULL)
{
printf("%dx^%d",poly->coeff,poly->expo);
poly=poly->next;
if(poly!=NULL)
{
printf("+");
}
}
printf("\n");
}
struct node*addpolynomials(struct node*poly1,struct node*poly2)
{
struct node*result=NULL;
struct node*temp1=poly1;
struct node*temp2=poly2;
while(temp1!=NULL&&temp2!=NULL)
{
if(temp1->expo==temp2->expo)
{
int sumcoeff=temp1->coeff+temp2->coeff;
if(sumcoeff!=0)
{
addnode(&result,sumcoeff,temp1->expo);
}
temp1=temp1->next;
temp2=temp2->next;
}
else if(temp1->expo>temp2->expo)
{
addnode(&result,temp1->coeff,temp1->expo);
temp1=temp1->next;
}
else
{
addnode(&result,temp2->coeff,temp2->expo);
temp2=temp2->next;
}
}
while(temp1!=NULL)
{
addnode(&result,temp1->coeff,temp1->expo);
temp1=temp1->next;
}
while(temp2!=NULL)
{
addnode(&result,temp2->coeff,temp2->expo);
temp2=temp2->next;
}
return result;
}
void inputpolynomial(struct node**poly)
{
int n,coeff,expo;
printf("enter the number of terms in the polynomial:");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("enter the coefficient and exponent for term%d:",i+1);
scanf("%d%d",&coeff,&expo);
addnode(poly,coeff,expo);
}
}
int main()
{
struct node*poly1=NULL;
struct node*poly2=NULL;
struct node*sum=NULL;
printf("input for polynomial 1:\n");
inputpolynomial(&poly1);
printf("input for polynomial 2:\n");
inputpolynomial(&poly2);
printf("polynomial 1:");
displaypolynomial(poly1);
printf("polynomial 2:");
displaypolynomial(poly2);
sum=addpolynomials(poly1,poly2);
printf("sum of polynomials:");
displaypolynomial(sum);
return 0;
}

