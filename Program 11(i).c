/*
Program 11(i):
        Program to implement a circular queue using an array and to perform INSERT and DELETE operations on it.
*/

#include <stdio.h>
#include <conio.h>

typedef struct
{
        int a[50];
        int front;
        int rear;
        int size;
        int check;
}queue;

void initialize(queue *q,int n)
{
     q->front=-1;
     q->rear=-1;
     q->size=n;
     q->check=0;
}

void ins(queue *q,int n)
{
     if(q->front==-1)
     {
                    q->front++;
     }
     
     q->rear=(q->rear+1)%q->size;
     q->a[q->rear]=n;
     q->check++;
     printf("\nFront=%d",q->front);
     printf("\nRear=%d",q->rear);

}
                    
int del(queue *q)
{
    int n;
    n=q->a[q->front];
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

void show(queue q)
{
     int i=q.front;
     if(q.front==-1)
                    return;
     else
     {
         while(i!=q.rear)
         {
               printf("%d ",q.a[i]);
               i=(i+1)%q.size;
         }
         printf("%d ",q.a[i]);
         printf("\n");
     }
}
     

int main()
{
    queue q;
    int ch=0,elem,size,i;
    
    printf("-----------------------------------------------------\n\n");
    printf(" Program to implement a circular queue using an array,\n To perform INSERT and DELETE operations.");
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
             
