/*
Program 12:
        Program to implement a priority queue using a 2D array.
*/

#include <stdio.h>
#include <conio.h>

typedef struct
{
        int a[2][50];
        int front;
        int rear;
        int size;
}pqueue;

void initialize(pqueue *q,int n)
{
     q->front=-1;
     q->rear=-1;
     q->size=n;
}

void ins(pqueue *q,int n,int p)
{
     int count;

     if((q->rear==-1)&&(q->front==-1))
     {
                    q->front++;
     }

     q->rear++;

     count=q->rear;
     while(p>q->a[1][count-1])
     {
     		q->a[0][count]=q->a[0][count-1];
         q->a[1][count]=q->a[1][count-1];
         count--;
     }
     q->a[0][count]=n;
     q->a[1][count]=p;
}



int del(pqueue *q)
{
    int n;
    n=q->a[0][q->front];
    (q->front)++;
    return n;
}



int isOverflow(pqueue q)
{
    if((q.rear>=(q.size-1))||(q.rear<q.front))
        return 1;
    else
        return 0;
}

int isUnderflow(pqueue q)
{
    if((q.rear<=-1)||(q.front>q.rear))
        return 1;
    else
        return 0;
}

void show(pqueue q)
{
     int i;
     printf("\nQueue:    ");
     for(i=q.front;i<=q.rear;i++)
     {
                         printf("%d ",q.a[0][i]);
     }
     printf("\n");
     printf("\nPriority: ");
     for(i=q.front;i<=q.rear;i++)
     {
                         printf("%d ",q.a[1][i]);
     }
     printf("\n");
}


int main()
{
    pqueue q;
    int ch=0,elem,size,prior;

    printf("--------------------------------------------------------\n\n");
    printf(" Program to implement a priority queue using a 2D array");
    printf("\n\n--------------------------------------------------------\n\n");

    printf("\nEnter size of the queue: ");
    scanf("%d",&size);
    initialize(&q,size);

    while(ch!=3)
    {
                printf("\n\n1. Press 1 to INSERT an element into the priority queue");
                printf("\n2. Press 2 to DELETE an element from the priority queue");
                printf("\n3. Press 3 to SHOW final priority queue and exit");
                printf("\n\nEnter choice: ");
                scanf("%d",&ch);

                switch(ch)
                {
                          case 1:
                               if (isOverflow(q))
                                  printf("\nOverflow");
                               else
                               {
                                   printf("\nEnter element to be inserted: ");
                                   scanf("%d",&elem);
                                   printf("\nEnter priority: ");
                                   scanf("%d",&prior);
                                   ins(&q,elem,prior);
                               }
                               break;
                          case 2:
                               if(isUnderflow(q))
                                                 printf("\nUnderflow");
                               else
                               {
                                          elem=del(&q);
                                          printf("\nThe deleted element is: %d",elem);
                               }
                               break;
                          case 3:
                               printf("\nThe final queue is:\n");
                               show(q);
                               break;
                          default:
                                  printf("\nWrong choice entered.");
                }
    }
    getch();
    return 0;
}

