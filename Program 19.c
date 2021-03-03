/*
  Program 19:
          Program to split a circular linked list into 2 separate circular linked lists.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define NULL 0

struct node
{
        int data;
        struct node *link;
};

typedef struct node node;

void create(node **start,int x,int pos)
{
     node *p, *new ;
     int count=1;

     new=(node *)malloc(sizeof(node));
     new->data=x;
     new->link=NULL;

     p=*start;
     while(count<pos)
     {
          p=p->link;
          count++;
     }

     new->link=p->link;
     p->link=new;
}

/*void ins(node **start,int x,int y,int ch)
{
     node *p, *new ;

     new=(node *)malloc(sizeof(node));
     new->data=x;
     new->link=NULL;

     if(ch==1)
     {
              p=*start;
              while(p->data!=y)
              {
                      p=p->link;
              }
     }

     else if(ch==2)
     {
          p=*start;
          while((p->link)->data!=y)
          {
                 p=p->link;
          }
     }

     new->link=p->link;
     p->link=new;
}

void del(node **start,int y)
{
     node *p,*q;

     p=*start;
     while((p->link)->data!=y)
     {
          p=p->link;
     }
     q=p->link;

     p->link=q->link;
} */

void display(node **start,int x)
{
     node *p;
     int count=1;

     p=*start;
     printf("\nStart --> ");
     while(count<=x)
     {
          p=p->link;
          printf("%d --> ",p->data);
          count++;
     }
     printf("Stop \n\n");
}

void split(node **start,node **start2, int x, int y)
{
	node *p;
   int count=0;

   p=*start;
   while(count<x)
   {
       p=p->link;
       count++;
   }

   (*start2)->link=p->link;
   p->link=*start;

   count=0;
   p=*start2;
   while(count<y)
   {
   	p=p->link;
      count++;
   }
   p->link=*start2;
}

int main()
{
    node *start,*start2;
    int size,x,y,i,elem,count=0;

    printf("------------------------------------------------------------------------------\n\n");
    printf(" Program to split a circular linked list into 2 separate circular linked lists");
    printf("\n\n------------------------------------------------------------------------------\n\n");

    start=(node *)malloc(sizeof(node));
    start->link=start;

    start2=(node *)malloc(sizeof(node));
    start2->link=start2;


    printf("\nCreation of circular linked list P: \n");

    printf("\nEnter size of linked list to be created: ");
    scanf("%d",&size);

    printf("\nEnter the %d elements: \n",size);
    for(i=1;i<=size;i++)
    {
    	scanf("%d",&elem);
      count++;
      create(&start,elem,count);
    }

	 printf("\nP:\n");
    display(&start,size);

    x=floor(size/2);
    y=size-x;
    printf("\nP is split into 2 circular linked lists Q and R with sizes %d and %d respectively\n\n",x,y);

    split(&start,&start2,x,y);

    printf("\nQ:\n");
    display(&start,x);

    printf("\nR:\n");
    display(&start2,y);

    getch();
    return 0;
}
