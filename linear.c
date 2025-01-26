#include<stdio.h>
int main()
{
int i,n,e,flag=-1;
printf("Enter the no of elements:");
scanf("%d",&n);
int a[n];
printf("Enter the elements in array:");
for (i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the no to be searched:");
scanf("%d",&e);
for(i=0;i<n;i++)
{
if (a[i]==e)
{
flag=i;
break;
}
}
if (flag!= -1)
{
printf("Element is found at position %d",flag+1);
}
else
{
printf("Element is not found");
}
}




