#include<stdio.h>
int main()
{
int temp,n,i,j;
printf("Enter the no of elements:");
scanf("%d",&n);
int arr[n];
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if (arr[j]>arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
printf("sorted array");
for(i=0;i<n;i++)
{
printf("%d",arr[i]);
}
}



 
