/*
Program 15:
				Program to create a sorted singly linked list, and to perform INSERT and DELETE operations")
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

int main(){
    node *start;
    int i,choice=0,count=0,size,elem,pos;

    printf("-----------------------------------------\n\n");
    printf(" Program to create a sorted singly linked list,\n To perform INSERT and DELETE operations");
    printf("\n\n-----------------------------------------\n\n");

    start=(node *)malloc(sizeof(node));
    start->link=NULL;
    start->data=0;

        while(choice!=5)
    {
                   					printf("\n1. Press 1 to create a new linked list");
                                 printf("\n2. Press 2 to insert a new node in the linked list at any position");
                                 printf("\n3. Press 3 to delete an existing node from the linked list");
                                 printf("\n4. Press 4 to print the linked list");
                                 printf("\n5. Press 5 to exit");
                                 printf("\n\nEnter choice: ");
                                 scanf("%d",&choice);


                switch(choice){
                               case 1:
                                    printf("\nEnter size of linked list to be created: ");
                                    scanf("%d",&size);
                                    printf("\nEnter the %d elements: \n",size);
                                    for(i=1;i<=size;i++){
                                                         scanf("%d",&elem);
                                                         count++;

                                                         insort(&start,elem);
                                    }
                               break;

                               case 2:{
                                    printf("\nEnter element to be inserted: ");
                                    scanf("%d",&elem);

                                    insort(&start,elem);
                               }break;

                               case 3:{
                                    printf("\nEnter position of element to be deleted: ");
                                    scanf("%d",&pos);

                                    del(&start,pos);
                               }break;

                               case 4:{
                                    printf("\nThe linked list is: \n");
                                    display(&start);
                               }break;

                               case 5:
                                    exit(0);
                                    break;

                               default:
                                  printf("\nWrong choice entered");
                }
    }

getch();
return(0);
}
