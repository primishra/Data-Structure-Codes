/*
Program 21:
        Program to evaluate a given POSTFIX expression using  linked stack.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char prec[]={'-','+','*','/','^'};

struct NODE{
       char data;
       struct NODE *link;
};
typedef struct NODE node;

struct NODE2{
       double data;
       struct NODE2 *link;
};
typedef struct NODE2 node2;


typedef struct
{
        node *start;
        int top;
        int size;
}stack;

typedef struct
{
        node2 *start;
        int top;
        int size;
}stack2;

void initialize(stack *s,int n)
{
     s->start=(node *)malloc(sizeof(node));
     (s->start)->data=0;
     (s->start)->link=NULL;
     s->size=n;
     s->top=-1;
}

void initialize2(stack2 *s,int n)
{
     s->start=(node *)malloc(sizeof(node));
     (s->start)->data=0;
     (s->start)->link=NULL;
     s->size=n;
     s->top=-1;
}

char traverse(node **start, int pos)
{
	node *prev;
   int count = 0;
   char x;

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
}*/

void ins(node **start, char x, int pos){
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

double traverse2(node2 **start, int pos)
{
	node *prev;
   int count = 0;
   double x;

   prev = *start;
   while(count<pos){
                 prev = prev->link;
            		count++;
   }
   x=prev->data;
   return x;
}



/*void del2(node2 **start, int pos){
     node *prev, *next;
     int count = 1;


     prev = *start;
     while(count<pos){
           prev = prev->link;
           count++;
     }

     next = prev->link;
     prev->link = next->link;
}*/

void ins2(node2 **start, double x, int pos){
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

void push(stack *s,char n)
{
     (s->top)++;
     ins(&s->start,n,(s->top)+1);
}

void push2(stack2 *s,double n)
{
     (s->top)++;
     ins2(&s->start,n,(s->top)+1);
}


char pop(stack *s)
{
    char n;
    n = traverse(&s->start,(s->top)+1);
    (s->top)--;
    return n;
}

double pop2(stack2 *s)
{
    double n;
    n = traverse2(&s->start,(s->top)+1);
    (s->top)--;
    return n;
}

/*char peep(stack s,int n)
{
    char x;
    x=s.a[(s.top-n)];
    return x;
}

void change(stack *s,int n,char x)
{
    stack t;
    char temp;
    int i;

    initialize(&t,50);


    for(i=1;i<=n;i++)
    {
                     temp=pop(s);
                     push(&t,temp);
    }
    temp=pop(s);
    push(s,x);
    for(i=1;i<=n;i++)
    {
                     temp=pop(&t);
                     push(s,temp);
    }
}*/

int isOverflow(stack s)
{
    if(s.top>=(s.size-1))
                    return 1;
    else
        return 0;
}

int isUnderflow(stack s)
{
    if(s.top<=-1)
                 return 1;
    else
        return 0;
}

/*void show(stack s)
{
     int i;
     for(i=s.top;i>=0;i--)
     {
                         printf("\n%c",s.a[i]);
     }
}*/

int highpreccheck(char a,char b)
{
    int x=-1,y=-1,i;
    if((a=='\0')&&(b=='\0'))
                            return -1;
    for(i=0;i<5;i++)
    {
                    if(prec[i]==a)
                    x=i;
                    if(prec[i]==b)
                    y=i;
    }

    if(x>y)
           return 1;
    else
        return 0;
}

double getopval(char *oplist, double *opval, int opcount, char c)
{
	int i=0;
   double x;

   while((oplist[i]!=c) && (i<opcount))
   {
   	i++;
   }

   if(oplist[i]==c)
   {
      x=opval[i];
      return x;
   }
   else
   	return 0;
}

int main()
{
    stack s;
    stack2 t;
    int ch=0,l,i,count=0,opcount=0;
    char exp[100],ans[100],c,d=' ',e,oplist[100];
    double opval[100],x,y,z;

    printf("-------------------------------------------------------------------\n\n");
    printf(" Program to evaluate a given POSTFIX expression using linked stack");
    printf("\n\n-------------------------------------------------------------------\n\n");


    initialize(&s,50);
    initialize2(&t,50);

    for(i=0;i<100;i++)
                      ans[i]=0;

    printf("\nEnter the Infix expression: ");
    gets(exp);

    printf("\nEntered Infix expression: \n");
    puts(exp);

    l=strlen(exp);

    for(i=0;i<=l;i++)
    {
             c=exp[i];

             if(((c>='(')&&(c<='/'))||(c=='^'))  //Operator or brackets
             {
                       if(c=='(')
                                 push(&s,c);


                       else if(c==')')
                       {
                            d=traverse(&s.start,(s.top)+1);
                            while(d!='(')
                            {
                                         e=pop(&s);
                                         ans[count]=e;
                                         count++;
                                         d=traverse(&s.start,(s.top)+1);
                            }
                            e=pop(&s);
                       }



                       else
                       {
                                   if(s.top>=0)
                                       d=traverse(&s.start,(s.top)+1);

                                   if(highpreccheck(c,d))
                                   {
                                       push(&s,c);
                                   }
                                   else
                                   {
                                       while(highpreccheck(c,d)==0)
                                       {
                                             e=pop(&s);
                                             ans[count]=e;
                                             count++;
                                             d=traverse(&s.start,(s.top)+1);
                                       }
                                       push(&s,c);
                                   }
                       }
             }

             else if(c!=0)       //Operand
             {
                 ans[count]=c;
                 count++;
                 oplist[opcount]=c;
                 opcount++;
             }

             else if(c==0)        //Sentinel
             {
                  while(isUnderflow(s)==0)
                  {
                         e=pop(&s);
                         ans[count]=e;
                         count++;
                  }
             }
    }

    printf("\nThe equivalent postfix expression is: \n");
    puts(ans);

    printf("\nEnter the values of all operands: \n");
    for(i=0;i<opcount;i++)
    {
    	printf("%c: ",oplist[i]);
      scanf("%lf",&opval[i]);
    }

    l=strlen(ans);

    for(i=0;i<=l;i++)
    {
     	c=ans[i];

      if(((c>='(')&&(c<='/'))||(c=='^'))  //Operator or brackets
      {
       	switch(c)
         {
         	case '+':
            	y=pop2(&t);
               x=pop2(&t);
               z=x+y;
               push2(&t,z);
               break;

            case '-':
            	y=pop2(&t);
               x=pop2(&t);
               z=x-y;
               push2(&t,z);
               break;

				case '*':
            	y=pop2(&t);
               x=pop2(&t);
               z=x*y;
               push2(&t,z);
               break;

				case '/':
            	y=pop2(&t);
               x=pop2(&t);
               z=x/y;
               push2(&t,z);
               break;

				case '^':
            	y=pop2(&t);
               x=pop2(&t);
               z=pow(x,y);
               push2(&t,z);
               break;

            default:
            	break;
         }


      }

      else if(c!=0)       //Operand
      {
      	x=getopval(oplist,opval,opcount,c);
      	push2(&t,x);

      }

      else if(c==0)        //Sentinel
      {
      	break;
      }
	}

    x=pop2(&t);
    printf("\n\nThe final evaluated answer is: %lf",x);

    getch();
    return 0;
}
