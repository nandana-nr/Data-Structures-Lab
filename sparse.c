#include<stdio.h>
struct sparse
{
int rows;
int col;
int value;
};
struct sparse s[20];
void sparse_matrix(int rows , int col,int arr[20][20])
{
int i,j;
int count =0 , k=1 ;
for(int i=0;i<rows;i++)
{
for(int j=0;j<col;j++)
{
if(arr[i][j]!=0)
{
s[k].rows=i;
s[k].col=j;
s[k].value=arr[i][j];
k++;
count++;
}
}
}
{
s[0].rows=rows;
s[0].col=col;
s[0].value=count;
};
printf("Sparse Matrix : \n");
printf("\n rows(%d) column(%d) value(%d)\n", s[0].rows,s[0].col,s[0].value);
for(i=1;i<k;i++)
{
printf("\n%d \t%d \t%d" , s[i].rows , s[i].col, s[i].value);
}
}
void main()
{
int row,column,i,j,value,a[20][20];
printf("Enter the number of rows:");
scanf("%d",&row);
printf("Enter the number of column :");
scanf("%d",&column); 
int arr[row][column];
printf("Enter elements of matrix : \n");
for(int i=0;i<row;i++)
{
for(int j=0;j<column;j++)
{
scanf("%d",&a[i][j]);
}
}
sparse_matrix(row,column,a);
}




