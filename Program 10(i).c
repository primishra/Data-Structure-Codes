/*
Program 10(i):
        Program to implement a linear queue using an array and to perform INSERT and DELETE operations on it.
*/

#include <stdio.h>
#include <conio.h>

typedef struct
{
        int a[50];
        int front;
        int rear;
        int size;
}queue;

void initialize(queue *q,int n)
{
     q->front=-1;
     q->rear=-1;
     q->size=n;
}

void ins(queue *q,int n)
{
     if((q->rear==-1)&&(q->front==-1))
     {
                    q->front++;
     }
     
     q->rear++;
     q->a[q->rear]=n;
}
                    


int del(queue *q)
{
    int n;
    n=q->a[q->front];
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

void show(queue q)
{
     int i;
     for(i=q.front;i<=q.rear;i++)
     {
                         printf("%d ",q.a[i]);
     }
     printf("\n");
}
     

int main()
{
    queue q;;
    int ch=0,elem,size;
    
    printf("-----------------------------------------------------\n\n");
    printf(" Program to implement a linear queue using an array,\n To perform INSERT and DELETE operations.");
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
                                   ins(&q,elem);
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
             
