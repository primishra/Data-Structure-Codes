/*
  Program 17:
          Program to create a doubly linked list, to perform INSERT and DELETE operations on it, and to count no. of nodes in it.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

struct node
{
        int data;
        struct node *llink;
        struct node *rlink;
};

typedef struct node node;

void create(node **start,int x,int pos)
{
     node *p, *q,*new ;
     int count=1;
     
     new=(node *)malloc(sizeof(node));
     new->data=x;
     new->llink=NULL;
     new->rlink=NULL;
     
     p=*start;
     while(count<pos)
     {
          p=p->rlink;
          count++;
     }

     if(p->rlink!=NULL)
     {
     		q=p->rlink;
         q->llink=new;
     }

     new->rlink=p->rlink;
     p->rlink=new;
     new->llink=p;
}

void ins(node **start,int x,int y,int ch)
{
     node *p, *q, *new ;

     new=(node *)malloc(sizeof(node));
     new->data=x;
     new->rlink=NULL;
     new->llink=NULL;

     if(ch==1)
     {
              p=*start;
              while(p->data!=y)
              {
                      p=p->rlink;
              }
     }

     else if(ch==2)
     {
          p=*start;
          while((p->rlink)->data!=y)
          {
                 p=p->rlink;
          }
     }

     if(p->rlink!=NULL)
     {
                q=p->rlink;
                q->llink=new;
     }
     new->rlink=p->rlink;
     p->rlink=new;
     new->llink=p;
}

void del(node **start,int y)
{
     node *p,*q,*r;

     p=*start;
     while((p->rlink)->data!=y)
     {
          p=p->rlink;
     }
     q=p->rlink;
     r=q->rlink;

     p->rlink=r;
     r->llink=p;
}

void display(node **start,int x)
{
     node *p;
     int count=1;

     p=*start;
     printf("\nStart --> ");
     while(count<=x)
     {
          p=p->rlink;
          printf("%d --> ",p->data);
          count++;
     }
     printf("Stop \n\n");
}

int main()
{
    node *start;
    int i,ch=0,count=0,size,elem,elem2,ch2=0;

    printf("-----------------------------------------\n\n");
    printf(" Program to create a doubly linked list,\n To perform INSERT and DELETE operations");
    printf("\n\n-----------------------------------------\n\n");

    start=(node *)malloc(sizeof(node));
    start->llink=NULL;
    start->rlink=NULL;


    while(ch!=6)
    {
                printf("\n1.Press 1 to create a new linked list");
                printf("\n2.Press 2 to insert a new node in the linked list at any position");
                printf("\n3.Press 3 to delete an existing node from the linked list");
                printf("\n4.Press 4 to print the linked list");
                printf("\n5.Press 5 to print the no. of nodes");
                printf("\n6.Press 6 to exit");
                printf("\n\nEnter choice: ");
                
                scanf("%d",&ch);
                switch(ch)
                {
                          case 1:
                               printf("\nEnter size of linked list to be created: ");
                               scanf("%d",&size);
                   
                               printf("\nEnter the %d elements: \n",size);
                               for(i=1;i<=size;i++)
                               {
                                                   scanf("%d",&elem);
                                                   count++;
                                                   create(&start,elem,count);
                               }
                   
                               break;
                   
                          case 2:
                               printf("\nEnter element to be inserted: ");
                               scanf("%d",&elem);
                               printf("\n.1 Press 1 to insert AFTER a particular node.");
                               printf("\n2. Press 2 to insert BEFORE a particular node.");
                               printf("\n\nEnter choice: ");
                               scanf("%d",&ch2);
                               switch(ch2)
                               {
                                          case 1:
                                               printf("\nEnter element after which insertion should take place: ");
                                               scanf("%d",&elem2);                
                                               ins(&start,elem,elem2,ch2);
                                               count++;
                                               break;
                                               
                                          case 2:
                                               printf("\nEnter element before which insertion should take place: ");
                                               scanf("%d",&elem2);
                                               ins(&start,elem,elem2,ch2);
                                               count++;
                                               break;
                                          
                                          default:
                                               printf("\nWrong choice entered");
                               }
                               break;
              
                          case 3:
                               printf("\nEnter element to be deleted: ");
                               scanf("%d",&elem2);
                               
                               del(&start,elem2);
                               count--;
                               
                               break;
                          
                          case 4:
                               printf("\nThe linked list is: \n");
                               display(&start,count);
                               
                               break;
                               
                          case 5:
                               printf("\nThe no. of nodes are: %d",count);
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
