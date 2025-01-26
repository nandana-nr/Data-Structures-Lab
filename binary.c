#include<stdio.h>
int main()
{
int n,left,right,mid,searchkey,i;
printf("Enter the size of the array:");
scanf("%d",&n);
int arr[n];
printf("Enter the elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
left=0;
right=n-1;
mid=(left+right)/2;
printf("Enter the value to be searched :");
scanf("%d",&searchkey);
while (left<=right)
{
if (arr[mid]==searchkey)
{
printf("Element is found at index %d \n",mid);
break;
}
else if (arr[mid]<searchkey)
{
left=mid+1;
}
else 
{
right = mid-1;
}
mid=(left+right)/2;
if(left>right)
{
printf("Element not found \n");
}
}
}







