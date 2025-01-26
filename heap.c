#include<stdio.h>
void create_heap(int ar[], int size)
{
int p,temp,i; 
for(i=size;i>=1;i--)
{
p=i/2; 
while(p>=1)
{
if(ar[p]<ar[i])
{
temp=ar[p]; 
ar[p]=ar[i]; 
ar[i]=temp;
}
p=p/2;
}
}
}

void rebuild_heap(int ar[], int size)
{
int lc,rc,temp,p=1,large; 
while(p<=size)
{
lc=2*p; 
rc=2*p+1;
if(lc<=size)
{ 
if(ar[lc]<ar[p])large=p;
else
large=lc;
}
if(rc<=size&&ar[large]<ar[rc]) large=rc;
if(p!=large)
{
temp=ar[p]; 
ar[p]=ar[large]; 
ar[large]=temp; 
p=large;}
else
break;
}
}

void main()
{
int ar[20],size,i,temp,size_backup;
printf("Enter number of elements:");
scanf("%d",&size);
printf("Enter elements:\n");
for(i=1;i<=size;i++)
scanf("%d",&ar[i]);
create_heap(ar, size);
size_backup=size;
while(size>1)
{
rebuild_heap(ar,size);
temp=ar[1]; 
ar[1]=ar[size]; 
ar[size]=temp;
size--;
}
printf("result is: ");
for(i=1;i<=size_backup;i++)
printf(" %d",ar[i]);}

