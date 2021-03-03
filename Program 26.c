/*
Program 26:
           Program to implement construction of a BST, and to:
                   a.	Insert element(s) into a non empty BST
                   b.	Delete element(s) from a non empty BST
                   c.	Search for an element in a BST
                   d.	Retrieve elements of the BST in a sorted order.
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

node * del(node **curr, int x)
{
     node *p,*p2;
     
     if((*curr)->data==x)
     {
            if(((*curr)->left==0) && ((*curr)->right==0))
            {
                   return 0;
            }
            
            else if((*curr)->left==0)
            {
                 p=(*curr)->right;
                 return p;
            }
            
            else if((*curr)->right==0)
            {
                 p=(*curr)->left;
                 return p;
            }
            
            else
            {
                p2=(*curr)->right;
                p=(*curr)->right;
                
                while(p->left !=0)
                       p=p->left;
                
                p->left=(*curr)->left;
                
                return p2;
            }
     }
     
     else if((*curr)->data<x)
         (*curr)->right=del(&((*curr)->right),x);
     
     else
         (*curr)->left=del(&((*curr)->left),x);
         
     return (*curr);
}                                    

void search(node *curr,int x)
{
     if(curr->data==x)
     {
             printf("\nElement found.");
             return;
     }
     
     else if((curr->data < x) && (curr->right!=0))
            search(curr->right,x);
     else if((curr->data > x) && (curr->left!=0))
            search(curr->left,x);
     else       
     printf("\nElement not found."); 
}

void inorder(node *curr)
{
 	if(curr->left!=NULL)
   	 inorder(curr->left);
   printf("%d ",curr->data);
 	if(curr->right != NULL)
   	 inorder(curr->right);
}

int main()
{
   node *root;
   int ch=0,size,i,elem;

   printf("-----------------------------------------------------\n\n");
   printf(" Program to implement construction of a BST, and to:\n a.Insert element(s) into a non empty BST\n b.Delete element(s) from a non empty BST\n c.Search for an element in a BST\n d.Retrieve elements of the BST in a sorted order.");
   printf("\n\n-----------------------------------------------------\n\n");
   
   root=(node *)malloc(sizeof(node));
   root=0;

   while(ch!=6)
   {

      printf("\n1. Press 1 to create a new binary search tree.");
   	  printf("\n2. Press 2 to insert an element into the BST");
   	  printf("\n3. Press 3 to delete an element from the BST");
   	  printf("\n4. Press 4 to search for an element in the BST");
      printf("\n5. Press 5 to retrieve elements of the BST in a sorted order");
      printf("\n6. Press 6 to exit");
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
         	printf("\nEnter element to be inserted: ");
         	scanf("%d",&elem);
         	ins(&root,elem);
            break;

         case 3:
         	printf("\nEnter element to be deleted: ");
         	scanf("%d",&elem);
         	root = del(&root,elem);
            break;

         case 4:
         	printf("\nEnter element to be searched: ");
            scanf("%d",&elem);
            search(root,elem);
            break;

         case 5:
         	printf("\nThe elements in sorted order are: \n");
         	inorder(root);         	
            break;

         case 6:
              break;
         
         default:
         	printf("\nWrong choice entered");

      }
	}
	getch();
   return 0;
}

