/*
Program 22:
           Program for creation of binary search tree and traversing it in Pre, Post and Inorder.

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

void preorder(node *curr)
{
   printf("%d ",curr->data);
 	if(curr->left!=NULL)
   	 preorder(curr->left);
 	if(curr->right != NULL)
   	 preorder(curr->right);
}

void inorder(node *curr)
{
 	if(curr->left!=NULL)
   	 inorder(curr->left);
   printf("%d ",curr->data);
 	if(curr->right != NULL)
   	 inorder(curr->right);
}

void postorder(node *curr)
{

 	if(curr->left!=NULL)
   	 postorder(curr->left);
 	if(curr->right != NULL)
   	 postorder(curr->right);
   printf("%d ",curr->data);
}

int main()
{
   node *root;
   int ch=0,size,i,elem;

   printf("--------------------------------------------\n\n");
   printf(" Program for creation of binary search tree\n and traversing it in Pre, Post and Inorder");
   printf("\n\n--------------------------------------------\n\n");
   
   root=(node *)malloc(sizeof(node));
   root=0;

   while(ch!=5)
   {

      printf("\n1. Press 1 to create a new binary search tree.");
   	  printf("\n2. Press 2 to traverse it in Pre Order.");
   	  printf("\n3. Press 3 to traverse it in In Order.");
   	  printf("\n4. Press 4 to traverse it in Post Order.");
      printf("\n5. Press 5 to exit.");
      printf("\n\nEnter choice: ");
      scanf("%d",&ch);

      switch(ch)
      {
      	case 1:
         	printf("\nEnter no. of nodes to input: ");
            scanf("%d",&size);

            printf("\nEnter the %d elements: ",size);
            for(i=1;i<=size;i++)
            {
            	scanf("%d",&elem);
               ins(&root,elem);
            }
            break;

         case 2:
         	printf("\nPre Order:\n");
            preorder(root);
            break;

         case 3:
         	printf("\nIn Order:\n");
            inorder(root);
            break;

         case 4:
         	printf("\nPost Order:\n");
            postorder(root);
            break;

         case 5:
         	break;

         default:
         	printf("\nWrong choice entered");

      }
	}
	getch();
   return 0;
}

