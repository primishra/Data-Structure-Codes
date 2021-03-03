/*
Program 6:
        Program to implement a stack in an array and to perform PUSH, POP, PEEP and CHANGE operations on it using functions.
*/

#include <stdio.h>
#include <conio.h>

typedef struct
{
        int a[50];
        int top;
        int size;
}stack;

void initialize(stack *s,int n)
{
     s->size=n;
     s->top=-1;
}

void push(stack *s,int n)
{
     (s->top)++;
     s->a[s->top]=n;
}

int pop(stack *s)
{
    int n;
    n=s->a[s->top];
    (s->top)--;
    return n;
} 
     
int peep(stack s,int n)
{
    int x;
    x=s.a[(s.top-n)];
    return x;
}

void change(stack *s,int n,int x)
{
    stack t;
    initialize(&t,50);
    int temp,i;
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
}

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

void show(stack s)
{
     int i;
     for(i=s.top;i>=0;i--)
     {
                         printf("\n%d",s.a[i]);
     }
}
     

int main()
{
    stack s;
    int ch=0,elem,pos,size;
    
    printf("--------------------------------------------------\n\n");
    printf(" Program to implement a stack in an array,\n To perform PUSH, POP, PEEP and CHANGE operations");
    printf("\n\n--------------------------------------------------\n\n");
    
    printf("\nEnter size of the stack: ");
    scanf("%d",&size);
    initialize(&s,size);
    
    while(ch!=5)
    {
                printf("\n\n1. Press 1 to PUSH an element into the stack");
                printf("\n2. Press 2 to POP an element from the stack");
                printf("\n3. Press 3 to PEEP an element in the stack");
                printf("\n4. Press 4 to CHANGE an element in the stack");
                printf("\n5. Press 5 to SHOW final stack and exit");
                printf("\n\nEnter choice: ");
                scanf("%d",&ch);
    
                switch(ch)
                {
                          case 1:
                               if (isOverflow(s))
                                  printf("\nOverflow");
                               else
                                   printf("\nEnter element to be pushed: ");
                                   scanf("%d",&elem);
                                   push(&s,elem);
                               break;
                          case 2:
                               if(isUnderflow(s))
                                                 printf("\nUnderflow");
                               else
                               {                             
                                                             elem=pop(&s);
                                                             printf("\nThe popped element is: %d",elem);
                               }
                               break;
                          case 3:
                               printf("\nEnter position from top to be peeped: ");
                               scanf("%d",&pos);
                               if(pos>s.top)
                                             printf("\nPosition doesn't exist");
                               else
                               {
                                   elem=peep(s,pos);
                                   printf("\nPeeped element: %d",elem);
                               }
                               break;
                          case 4:
                               printf("\nEnter position from top of element to be changed: ");
                               scanf("%d",&pos);
                               if(pos>s.top)
                                             printf("\nPosition doesn't exist");
                               else
                               {                              
                                                              printf("\nEnter new element: ");
                                                              scanf("%d",&elem);
                                                              change(&s,pos,elem);
                               }
                               break;
                          case 5:
                               printf("\nThe final stack is:\n");
                               show(s);
                               break;
                          default:
                                  printf("\nWrong choice entered.");
                }
    }           
    getch();
    return 0;
}
             
