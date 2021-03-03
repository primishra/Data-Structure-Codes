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
}queue;

void initialize(queue *q,int n)
{
     q->start=(node *)malloc(sizeof(node));
     q->start->link=NULL;
     q->start->data=0;
     q->front=-1;
     q->rear=-1;
     q->size=n;
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



void del(node **start, int pos){
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

void display(queue q)
{
     int i;

     printf("\nStart --> ");

     for(i=(q.front)+1;i<=(q.rear)+1;i++)
     {

          printf("%d --> ", traverse(&(q.start),i));
     }
     printf("Stop \n\n");
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

}


void qins(queue *q,int n)
{
     if((q->rear==-1)&&(q->front==-1))
     {
                    q->front++;
     }

     q->rear++;
     ins(&(q->start), n, (q->rear)+1);
     printf("\nFront = %d Rear = %d",q->front, q->rear);

}

int qdel(queue *q)
{
    int n;
    n=traverse(&(q->start),(q->front)+1);
    (q->front)++;
    return n;
}



int isOverflow(queue q)
{
    if((q.rear>=(q.size-1))||(q.rear<q.front))
        return 1;
    else
        return 0;
}

int isUnderflow(queue q)
{
    if((q.rear<=-1)||(q.front>q.rear))
        return 1;
    else
        return 0;
}

int main(){
    int i,ch=0,count=0,size,elem,pos;
    queue q;

    printf("-----------------------------------------------------\n\n");
    printf(" Program to implement a linear queue using a linked list,\n To perform INSERT and DELETE operations.");
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
return(0);
}
