#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *link;
};

typedef struct node node;

void ins(node **start,int x,int pos)
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

void del(node **start,int pos)
{
     node *p,*q;
     int count=1;

     p=*start;
     while(count<pos)
     {
          p=p->link;
          count++;
     }
     q=p->link;

     p->link=q->link;
}

void display(node **start)
{
     node *p;

     p=*start;

     printf("\nStart --> ");
     while(p->link!=NULL)
     {
          p=p->link;
          printf("%d --> ",p->data);
     }
     printf("Stop \n\n");
}

int main()
{
    node *start;
    int i,ch=0,count=0,size,elem,pos;

    printf("-----------------------------------------\n\n");
    printf(" Program to create a singly linked list,\n To perform INSERT and DELETE operations");
    printf("\n\n-----------------------------------------\n\n");

    start=(node *)malloc(sizeof(node));
    start->link=NULL;

    while(ch!=5)
    {
                printf("\n1. Press 1 to create a new linked list");
                printf("\n2. Press 2 to insert a new node in the linked list at any position");
                printf("\n3. Press 3 to delete an existing node from the linked list");
                printf("\n4. Press 4 to print the linked list");
                printf("\n5. Press 5 to exit");
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
                                                   ins(&start,elem,count);
                               }

                               break;

                          case 2:
                               printf("\nEnter element to be inserted: ");
                               scanf("%d",&elem);
                               printf("\nEnter position for insertion: ");
                               scanf("%d",&pos);

                               ins(&start,elem,pos);

                               break;

                          case 3:
                               printf("\nEnter position of element to be deleted: ");
                               scanf("%d",&pos);

                               del(&start,pos);

                               break;

                          case 4:
                               printf("\nThe linked list is: \n");
                               display(&start);

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
