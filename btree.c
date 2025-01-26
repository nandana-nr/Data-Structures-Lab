#include<stdio.h>
#define MAX_SIZE 100
int binaryTree[MAX_SIZE];
int currentIndex=0;

void insertNode(int value)
{
if(currentIndex<MAX_SIZE)
{
binaryTree[currentIndex]=value;
currentIndex++;
printf("Inserted %d into the binary tree\n",value);
}
else
{
printf("Binary Tree is full. Cannot insert %d\n",value);
}
}

void inorderTraversal(int index)
{
if(index<currentIndex)
{
inorderTraversal(2*index+1);
printf("%d",binaryTree[index]);
inorderTraversal(2*index+2);
}
}

void preorderTraversal(int index)
{
if(index<currentIndex)
{
printf("%d",binaryTree[index]);
preorderTraversal(2*index+1);
preorderTraversal(2*index+2);
}
}

void postorderTraversal(int index)
{
if(index<currentIndex)
{
postorderTraversal(2*index+1);
postorderTraversal(2*index+2);
printf("%d",binaryTree[index]);
}
}

int findIndex(int value,int index)
{
if(index>=currentIndex)
{
return-1;
}
if(binaryTree[index]==value)
{
return index;
}
int leftchildIndex=2*index+1;
int rightchildIndex=2*index+2;
int foundIndex=findIndex(value,leftchildIndex);
if(foundIndex==-1)
{
foundIndex=findIndex(value,rightchildIndex);
}
return foundIndex;
}

void deleteNode(int value)
{
if(currentIndex==0)
{
printf("Cannot delete from an empty tree\n");
}
int indexToDelete=findIndex(value,0);
if(indexToDelete!=-1)
{
int lastNodeValue=binaryTree[currentIndex-1];
binaryTree[indexToDelete]=lastNodeValue;
currentIndex--;
printf("Deleted %d from binary Tree\n",value);
}
else
{
printf("Node with value %d not found \n",value);
}
}

int main()
{
int choice,value;
do
{
printf("\nBinary Tree Operations:\n");
printf("1.Insert Node\n");
printf("2.Delete Node\n");
printf("3.Inorder Traversal\n");
printf("4.Preorder Traversal\n");
printf("5.Postorder Traversal\n");
printf("6.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("Enter the value to insert:");
scanf("%d",&value);
insertNode(value);
break;
case 2:
printf("Enter the value to delete:");
scanf("%d",&value);
deleteNode( value);
break;
case 3:
printf("Inorder Traversal:");
inorderTraversal(0);
printf("\n");
break;
case 4:
printf("Preorder Traversal:");
preorderTraversal(0);
printf("\n");
break;
case 5:
printf("Postorder Traversal:");
postorderTraversal(0);
printf("\n");
break;
case 6:
printf("Exited\n");
break;
default:
printf("Invalid choice! Please select a valid option\n");
break;
}
}
while(choice!=6);
return 0;
}

