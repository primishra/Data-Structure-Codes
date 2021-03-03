/*
Program 11(i):
        Program to implement a circular queue using a linked list and to perform INSERT and DELETE operations on it.
*/

#include <stdio.h>
#include <conio.h>

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct NODE{
       int data;
       struct NODE *link;
};
typedef struct NODE node;

typedef struct
{
        node *start;
        int front;
        int rear;
        int size;
        int check;
}queue;

void addnode(node **start)
{
	node *p,*new;

   new=(node *)malloc(sizeof(node));
   new->data=0;
   new->link=NULL;

   p=*start;
   while(p->link!=NULL)
   {
   	p=p->link;
   }

   new->link=p->link;
   p->link=new;

}

void initialize(queue *q,int n)
{
     int i;

     q->start=(node *)malloc(sizeof(node));
     q->start->link=NULL;
     q->start->data=0;
     q->front=-1;
     q->rear=-1;
     q->size=n;
     q->check=0;

     for(i=1;i<=q->size;i++)
     {
     		addnode(&(q->start));
     }


}


void update(node **start, int x, int pos)
{
	node *prev;
   int count = 0;

   prev = *start;
   while(count<pos){
                 prev = prev->link;
            		count++;
   }
   prev->data=x;
}

int traverse(node **start, int pos)
{
	node *prev;
   int count = 0,x;

   prev = *start;
   while(count<pos){
                 prev = prev->link;
            		count++;
   }
   x=prev->data;
   return x;
}



/*void del(node **start, int pos){
     node *prev, *next;
     int count = 1;


     prev = *start;
     while(count<pos){
           prev = prev->link;
           count++;
     }

     next = prev->link;
     prev->link = next->link;
}

void ins(node **start, int x, int pos){
     node *prev, *new;
     int count = 1;

     new = (node *)malloc(sizeof(node));
     new->data = x;
     new->link = NULL;

     prev = *start;
     while(count<pos){
                 prev = prev->link;
            		count++;
     			}

 	new->link = prev->link;
  	prev->link = new;

} */


void qins(queue *q,int n)
{
     if(q->front==-1)
     {
                    q->front++;
     }

     q->rear=(q->rear+1)%q->size;
     update(&(q->start), n, (q->rear)+1);
     q->check++;
     printf("\nFront=%d",q->front);
     printf("\nRear=%d",q->rear);
}

int qdel(queue *q)
{
    int n;
    n=traverse(&(q->start),(q->front)+1);
    q->check--;

    if(q->check>0)
    	q->front=(q->front+1)%q->size;
    else
    	q->front=-1;

    printf("\nFront=%d",q->front);
    printf("\nRear=%d",q->rear);
    return n;
}

int isOverflow(queue q)
{
    if(q.check==q.size)
        return 1;
    else
        return 0;
}

int isUnderflow(queue q)
{
    if(q.check==0)
        return 1;
    else
        return 0;
}

void display(queue q)
{
     int i=q.front;
          printf("\nStart --> ");
     if(q.front==-1)
     			{
            	printf("Stop \n\n");
            	return;
            }

     else
     {
         while(i!=q.rear)
         {
               printf("%d --> ",traverse(&(q.start),(i+1)));
               i=(i+1)%q.size;
         }
         printf("%d --> ",traverse(&(q.start),i+1));
         printf("Stop \n\n");
     }
}

int main()
{
    queue q;
    int ch=0,elem,size,i;

    printf("-----------------------------------------------------\n\n");
    printf(" Program to implement a circular queue using a linked list,\n To perform INSERT and DELETE operations.");
    printf("\n\n-----------------------------------------------------\n\n");

    printf("\nEnter size of the queue: ");
    scanf("%d",&size);
    initialize(&q,size);

    while(ch!=3)
    {
                printf("\n\n1. Press 1 to INSERT an element into the queue");
                printf("\n2. Press 2 to DELETE an element from the queue");
                printf("\n3. Press 3 to SHOW final queue and exit");
                printf("\n\nEnter choice: ");
                scanf("%d",&ch);

                switch(ch)
                {
                          case 1:
                               if (isOverflow(q))
                                  printf("\nOverflow");
                               else
                               {
                                   printf("\nEnter element to be pushed: ");
                                   scanf("%d",&elem);
                                   qins(&q,elem);
                               }
                               break;
                          case 2:
                               if(isUnderflow(q))
                                                 printf("\nUnderflow");
                               else
                               {
                                                             elem=qdel(&q);
                                                             printf("\nThe deleted element is: %d",elem);
                               }
                               break;
                          case 3:
                               printf("\nThe final queue is:\n");
                               display(q);
                               break;
                          default:
                                  printf("\nWrong choice entered.");
                }
    }
    getch();
    return 0;
}

