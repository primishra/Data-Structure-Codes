/*
  Program 20:
          Program to maintain a list of car models, their price, name of the manufacturer, engine capacity etc., as a doubly linked list,
          with provisions for inserting new car models, delete obsolete models, and update data such as price.
          also listing all car models within a price range specified by the user and listing all details given a car model.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0

struct node
{
        char model[100];
        double price;
        char manufacturer[100];
        double capacity;
        struct node *llink;
        struct node *rlink;
};

typedef struct node node;

void create(node **start,char *mod,double pri, char *manu, double cap, int pos)
{
     node *p, *q, *new;
     int count=1;

     new=(node *)malloc(sizeof(node));

     new->llink=NULL;
     new->rlink=NULL;
     strcpy(new->model, mod);
     strcpy(new->manufacturer, mod);
     new->price=pri;
     new->capacity=cap;

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

void insort(node **start,char *mod, double pri, char *manu, double cap)
{
     node *p, *q, *new ;

     new=(node *)malloc(sizeof(node));
     strcpy(new->model, mod);
     strcpy(new->manufacturer, manu);
     new->price=pri;
     new->capacity=cap;
     new->rlink=NULL;
     new->llink=NULL;

     p = *start;
	  if(p->rlink != NULL)
               q = p->rlink;
 	  else
     {
               q = (node *)malloc(sizeof(node));
               q->price = 100000000;
               q->rlink = NULL;
               q->llink = NULL;
     }

 		while(new->price > q->price)
      {
                 p = p->rlink;
                 if(p->rlink != NULL)
                      q = p->rlink;
                 else
                 {
                      q = (node *)malloc(sizeof(node));
                      q->price = 100000000;
                      q->llink = NULL;
                      q->rlink = NULL;
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

void del(node **start,char *mod)
{
     node *p,*q,*r;

     p=*start;
     while(strcmp((p->rlink)->model,mod)!=0)
     {
          p=p->rlink;
     }
     q=p->rlink;
     r=q->rlink;

     p->rlink=r;
     r->llink=p;
}

node ** traverse(node **start, char *mod)
{
      node *p;

      p=*start;
      while(strcmp(p->model,mod)!=0)
      {
      	p=p->rlink;
      }

      return &p;
}

void display(node **start,int x)
{
     node *p;
     int count=1;

     p=*start;
     while(count<=x)
     {
          p=p->rlink;
          puts(p->model);
          count++;
     }
}

void pricedisplay(node **start, double l, double u)
{
	node *p,*q, *start2;
   int count=1;

   start2=(node *)malloc(sizeof(node));
   start2->rlink=NULL;
   start2->llink=NULL;

   p=*start;
   while(p->price<l)
   {
      	p=p->rlink;
   }

   q=p;
   while((q->rlink)->price<u)
   {
   	q=q->rlink;
   	count++;
   }

	start2->rlink=p;
   display(&start2,count);

}

int main()
{
    node *start, *p;
    int i,ch=0,ch2=0,count=0,size,elem,elem2;
    char mod[100],manu[100];
    double pri,cap,l,u;

    printf("-----------------------------------------------------\n\n");
    printf(" Program to create and maintain a list of car models");
    printf("\n\n-----------------------------------------------------\n\n");

    start=(node *)malloc(sizeof(node));
    start->llink=NULL;
    start->rlink=NULL;


    while(ch!=8)
    {
                printf("\n1.Press 1 to create a new list of car models");
                printf("\n2.Press 2 to insert a new model");
                printf("\n3.Press 3 to delete an existing obsolete model");
                printf("\n4.Press 4 to update the data of a specific model");
                printf("\n5.Press 5 to print all models within a speicified price range");
                printf("\n6.Press 6 to print all details of a specific model");
                printf("\n7.Press 7 to print current list");
                printf("\n8.Press 8 to exit");
                printf("\n\nEnter choice: ");

                scanf("%d",&ch);
                switch(ch)
                {
                          case 1:
                               printf("\nEnter no. of models to be added: ");
                               scanf("%d",&size);

                               printf("\nEnter the %d model: \n",size);
                               for(i=1;i<=size;i++)
                               {
                                                   printf("\nModel %d: ",i);
                                                   scanf("%s",&mod);
                                                   printf("\nPrice: ");
                                                   scanf("%lf",&pri);
                                                   printf("\nManufacturer: ");
																	scanf("%s",&manu);
                                                   printf("Engine Capacity (in litres): ");
                                                   scanf("%lf",&cap);
                                                   count++;
                                                   insort(&start,mod,pri,manu,cap);

                               }
                               printf("\n\nEntered list: \n");
                                                   display(&start,count);

                               break;

                          case 2:
                                    printf("\nEnter the model to be inserted: ");
                                    scanf("%s",&mod);
                                    printf("\nPrice: ");
                                    scanf("%lf",&pri);
                                    printf("\nManufacturer: ");
                                    scanf("%s",&manu);
                                    printf("Engine Capacity (in litres): ");
                                    scanf("%lf",&cap);

                                    count++;
                                    insort(&start,mod,pri,manu,cap);
                               break;

                          case 3:
                               printf("\nEnter model to be deleted: ");
                               scanf("%s",&mod);

                               del(&start,mod);
                               count--;

                               break;

                          case 4:
                               printf("\nEnter the model to be updated: ");
                               scanf("%s",&mod);
                               p=*(traverse(&start, mod));

                               printf("\n1. Press 1 to update model name.");
                               printf("\n2. Press 2 to update price.");
                               printf("\n3. Press 3 to update name of manufacturer.");
                               printf("\n4. Press 4 to update engine capacity.");
                               printf("\n\nEnter choice: ");
                               scanf("%d",&ch2);

                               switch(ch2)
                               {
                               	case 1:
                                 	printf("\nEnter new model name: ");
                                    scanf("%s",&mod);
                                    strcpy(p->model,mod);
                                    break;

                                 case 2:
                                 	printf("\nEnter new price: ");
                                    scanf("%lf",&pri);

                                    strcpy(mod,p->model);
                                    strcpy(manu,p->manufacturer);
                                    cap=p->capacity;
                                    del(&start,mod);
                                    insort(&start,mod,pri,manu,cap);
                                    break;

                                 case 3:
                                 	printf("\nEnter new manufacturer name: ");
                                    scanf("%s",&manu);
												strcpy(p->manufacturer,manu);
                                    break;

                                 case 4:
                                 	printf("\nEnter new engine capacity (in litres): ");
                                    scanf("%lf",&cap);
                                    p->capacity=cap;
                                    break;

                           		default:
                                 	 printf("\nWrong choice entered.");
                               }


                               printf("\nThe no. of nodes are: %d",count);
                               break;

                          case 5:
                          		 printf("Enter lower price value: ");
                               scanf("%lf",&l);
                          		 printf("Enter upper price value: ");
                               scanf("%lf",&u);

                               pricedisplay(&start,l,u);
                               break;

                          case 6:
                               printf("\nEnter the model to be printed: ");
                               scanf("%s",&mod);
                               p=*(traverse(&start, mod));

                               printf("\n\nModel name: ");
                               printf("%s",p->model);
                               printf("\nPrice: %lf",p->price);
                               printf("\nManufacturer: ");
                               printf("%s",p->manufacturer);
                               printf("\nEngine Capacity : %lf litres ",p->capacity);
                               break;

                          case 7:
                          		 display(&start,count);
                               break;

                          case 8:
                          		 break;
                          default:
                                  printf("\nWrong choice entered");
              }
    }

    getch();
    return 0;
}
