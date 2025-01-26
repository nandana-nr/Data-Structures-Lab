#include<stdio.h>

void quick_sort(int arr[], int first, int last)
{
int i, j, pivot, temp;
if(first < last)
{
pivot = first; i = first;
j = last; 
while(i < j)
{
while(arr[i]<=arr[pivot] && i<last)
{ 
i++;
}
while(arr[j] > arr[pivot]) 
{
j--;
}
if(i < j)
{
temp = arr[i]; 
arr[i] = arr[j]; 
arr[j] = temp;
}
}
temp = arr[pivot]; 
arr[pivot] = arr[j];
arr[j] = temp; 
quick_sort(arr, first, j-1);
quick_sort(arr, j+1, last);
}
}

void main()
{
int n, ar[20];
printf("Enter the number of elements in the array: "); 
scanf("%d",&n);
printf("Enter the elements in the array: \n"); 
for(int i=0;i<n;i++)
{
scanf("%d",&ar[i]);
}
printf("\nBefore Sorting: ");
for(int i=0;i<n;i++)
{
printf("%d ",ar[i]);
}
quick_sort(ar, 0, n-1);
printf("\n\nAfter Sorting: "); 
for(int i=0;i<n;i++)
{
printf("%d ",ar[i]);
}
}
	

