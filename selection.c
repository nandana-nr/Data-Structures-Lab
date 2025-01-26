#include<stdio.h>
int main()
{
int n,i,j,min,temp;
printf("Enter the no of elements:");
scanf("%d",&n);
int arr[n];
printf("Enter %d elements : \n", n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if (arr[j]<arr[min])
{
min=j;
temp=arr[min];
arr[min]=arr[i];
arr[i]=temp;
}
}
}
printf("Sorted array");
for(int i=0;i<n;i++)
{
printf("%d \n",arr[i]);
}
}




