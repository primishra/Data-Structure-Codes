/*
Program 8:
			Program to implement a stack S of n elements using arrays, and to:
			a.	Retrieve the mth element of the stack S from the top (m < n), leaving the stack without its top m - 1 elements.
			b.	Retain only the elements in the odd position of the stack and pop out all even positioned elements.
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

/*int peep(stack s,int n)
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

void show(stack s)
{
     int i;
     for(i=s.top;i>=0;i--)
     {
                         printf(" %d ",s.a[i]);
     }
}



int main()
{
	int size,n,i,x,p,m;
	stack s,t,u;

   printf("--------------------------------------------------------------------\n\n");
   printf(" Program to implement a stack S of n elements using arrays, and to:\n\n a.Retrieve the mth element of the stack S from the top (m < n),\n   leaving the stack without its top m - 1 elements.\n\n b.Retain only the elements in the odd position of the stack,\n   and pop out all even positioned elements.");
   printf("\n\n--------------------------------------------------------------------\n\n");

	printf("\nEnter size of stack: ");
	scanf("%d",&size);

	initialize(&s,size);
	initialize(&t,size);
	initialize(&u,size);

	printf("\nEnter no. of elements to be inputted: ");
	scanf("%d",&n);
	printf("\nEnter the %d elements of stack:\n ",n);

	for(i=1;i<=n;i++)
   {
       scanf("%d",&x);
       push(&s,x);
   }

	printf("\n\nPart a: To retrieve the mth element of the stack S from the top (m < n),\n        leaving the stack without its top m - 1 elements.\n");

	printf("\nEnter the value of m (<n): ");
	scanf("%d",&m);

	for(i=1;i<m;i++)
	{
		p=pop(&s);
 	}
	printf("\nThe %dth element in the stack from top = %d",m,s.a[s.top]);

	printf("\n\nPart b: To retain only the elements in the odd position of the stack,\n         and pop out all even positioned elements.\n");

	while(s.top>=0)
	{
		if(isUnderflow(s))
		{
			printf("\nUnderflow");
			break;
		}
		else
		{
			p=pop(&s);
			if(((s.top+1)%2)!=0)
				push(&t,p);
		}
	}

	while(t.top>=0)
	{
		p=pop(&t);
		push(&u,p);
	}

	printf("\nFinal stack:\n");
	show(u);
	getch();
	return 0;
}