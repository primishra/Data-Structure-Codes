/*
Program 30:
           Program to implement binary search on an ordered list and to compare the no. of key comparisons in different elements.
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

node ** create(int *arr,int size)
{
     node *x,*y;
     int mid,lsize,r,rsize,n;
     
     n=size-1;
     
     if(n>1)
     {
            mid=n/2;
            lsize=mid;
            r=mid+1;
            rsize=n-mid;
     
            x=(node *)malloc(sizeof(node));
            x->data=*(arr+mid);
            x->left=*(create(arr,lsize));
            x->right=*(create((arr+r),rsize));
     }
     else if(n==1)
     {
            x=(node *)malloc(sizeof(node));
            x->data=*(arr);
            x->left=0;
            x->right=*(create((arr+1),1));
     }
     
     else if(n==0)
     {
            x=(node *)malloc(sizeof(node));
            x->data=*(arr);
            x->left=0;
            x->right=0;
     }
     return(&x);
}

int search(node *curr,int x)
{
     if(curr->data==x)
     {
             printf("\nElement found.");
             return 1;
     }
     
     else if((curr->data < x) && (curr->right!=0))
             return (1 + search(curr->right,x) );
     
     else if((curr->data > x) && (curr->left!=0))
             return (1+ search(curr->left,x) );
     else       
     {
             printf("\nElement not found.");
             return 0;
     }

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
   int l[100],ch=0,size,i,elem,n,x;

   printf("-------------------------------------------------------------\n\n");
   printf(" Program to implement binary search on an ordered list and\n To compare the no. of key comparisons in different elements");
   printf("\n\n-------------------------------------------------------------\n\n");
   
   while(ch!=3)
   {
      printf("\n1. Press 1 to create a new ordered list");
   	  printf("\n2. Press 2 to implement binary search for an element in the list");
   	  printf("\n3. Press 3 to exit");
   	  printf("\n\nEnter choice: ");
      scanf("%d",&ch);

      switch(ch)
      {
      	case 1:
         	printf("\nEnter no. of elements to input: ");
            scanf("%d",&n);

            printf("\nEnter the %d elements: ",n);
            for(i=0;i<n;i++)
            {
               scanf("%d",&l[i]);
            }
            root=*(create(l,n));
            printf("\nThe binary tree in Inorder is: \n");
            inorder(root);
            break;

         case 2:
         	printf("\nEnter element to be searched: ");
            scanf("%d",&elem);
            x=search(root,elem);
            if(x>0)
                   printf("\nThe no. of key comparisons are: %d",x);
            else
                   printf("\nThe no. of key comparisons are: %d",n);
            break;

         case 3:
              break;
         
         default:
         	printf("\nWrong choice entered");

      }
	}
	getch();
   return 0;
}

