/*
Program 18:
				Program to merge two singly linked lists X and Y, having sorted elements.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct NODE{
       int data;
       struct NODE *link;
};
typedef struct NODE node;


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

void display(node **start)
{
     node *prev;
     prev=*start;

     printf("\nStart --> ");

     while(prev->link!=NULL)
     {
          prev=prev->link;
          printf("%d --> ", prev->data);
     }
     printf("Stop \n\n");
}

void insort(node **start, int x){

 node *p, *new, *q;

 new = (node *)malloc(sizeof(node));
 new->data = x;
 new->link = NULL;

 p = *start;
 if(p->link != NULL)
               q = p->link;
 else{
               q = (node *)malloc(sizeof(node));
               q->data = 65000;
               q->link = NULL;
 }

 while(new->data > q->data){
                 p = p->link;
                      if(p->link != NULL)
                                    q = p->link;
                      else{
                           q = (node *)malloc(sizeof(node));
                           q->data = 65000;
                           q->link = NULL;
                           }
 }

 new->link = p->link;
  p->link = new;

}

void merge(node **start1, node **start2)
{
	node *p;

   p=*start1;
   while(p->link!=NULL)
   {
   	p=p->link;
   }

   p->link=(*start2)->link;
}

void bubsort(node **start, int size)
{
		node *p, *q;
      int i,count,temp;

      for(i=1;i<size;i++)
      {
           count=1;

           p=(*start)->link;
           while(count<=(size-i))
           {
                q=p->link;
                if(p->data > q->data)
                {
                	temp=p->data;
                  p->data=q->data;
                  q->data=temp;
                }
                p=q;
                count++;
           }
      }
}



int main(){
    node *startx,*starty;
    int i,choice=0,count=0,sizex,sizey,elem,pos;

    printf("-----------------------------------------\n\n");
    printf(" Program to create a sorted singly linked list,\n To perform INSERT and DELETE operations");
    printf("\n\n-----------------------------------------\n\n");

    startx=(node *)malloc(sizeof(node));
    startx->link=NULL;
    startx->data=0;

    starty=(node *)malloc(sizeof(node));
    starty->link=NULL;
    starty->data=0;

        printf("\nLinked list X:\n");
        printf("\nEnter size of linked list to be created: ");
        scanf("%d",&sizex);
        printf("\nEnter the %d elements: \n",sizex);

        for(i=1;i<=sizex;i++){
                  scanf("%d",&elem);
                  count++;
                  insort(&startx,elem);
        }

        printf("\nSorted Linked list X:\n\n");
        display(&startx);

        printf("\nLinked list Y:\n\n");
        printf("\nEnter size of linked list to be created: ");
        scanf("%d",&sizey);
        printf("\nEnter the %d elements: \n",sizey);

        for(i=1;i<=sizey;i++){
                  scanf("%d",&elem);
                  count++;
                  insort(&starty,elem);
        }

        printf("\nSorted linked list Y:\n\n");
        display(&starty);

        merge(&startx,&starty);

        printf("\nMerged Linked List (without re-sorting):\n");
        display(&startx);

        bubsort(&startx,(sizex+sizey));

        printf("\nMerged Linked List (after re-sorting): \n");
        display(&startx);

getch();
return(0);
}
