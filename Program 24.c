/*
Program 22:
           Program for creation of binary search tree and counting the no. of leaves in it.

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

struct node
{
	int data;
   struct node *left;
   struct node *right;
};
typedef struct node node;

void ins(node **curr, int x)
{
    if(*curr == 0)
    {
        *curr = (node *) malloc(sizeof(node));
        (*curr)->data = x;
        (*curr)->left = 0;
        (*curr)->right = 0;
    }
    else if(x < (*curr)->data)
         ins(&(*curr)->left,x);

    else if(x > (*curr)->data)
         ins(&(*curr)->right,x);
}

int leaves(node *curr)
{
  if(curr==0)
    return 0;
  if(curr->left == 0 && curr->right==0)
    return 1;
  else
    return (leaves(curr->left)+leaves(curr->right));
}

int main()
{
   node *root;
   int ch=0,size,i,elem,l=0;

   printf("--------------------------------------------------------------------------------\n\n");
   printf(" Program for creation of binary search tree and counting the no. of leaves in it");
   printf("\n\n--------------------------------------------------------------------------------\n\n");
   
   root=(node *)malloc(sizeof(node));
   root=0;
   
   printf("\nEnter no. of nodes to input: ");
   scanf("%d",&size);

   printf("\nEnter the %d elements: ",size);
   for(i=1;i<=size;i++)
   {
       scanf("%d",&elem);
       ins(&root,elem);
   }

   printf("\nThe no. of leaves in the tree are: %d",leaves(root));
   
   getch();
   return 0;
}

