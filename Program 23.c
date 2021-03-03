/*
Program 23:
        Program to create an expression tree and traverse it in Inorder.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

char prec[]={' ','-','+','*','/','^'};

struct node
{
   char data;
   struct node *left;
   struct node *right;
};
typedef struct node node;

typedef struct
{
        char a[50];
        int top;
        int size;
}stack;

typedef struct
{
        node * a[50];
        int top;
        int size;
}stack2;

void initialize(stack *s,int n)
{
     s->size=n;
     s->top=-1;
}

void initialize2(stack2 *s,int n)
{
     s->size=n;
     s->top=-1;
}

void push(stack *s,char n)
{
     (s->top)++;
     s->a[s->top]=n;
}

void push2(stack2 *s,node **n)
{
     (s->top)++;
     s->a[s->top]=*n;
}

char pop(stack *s)
{
    char n;
    n=s->a[s->top];
    (s->top)--;
    return n;
}

node ** pop2(stack2 *s)
{
    node *n;
    n=s->a[s->top];
    (s->top)--;
    return(&n);
}

int highpreccheck(char a,char b)
{
    int x=-1,y=-1,i;
    if((a=='\0')&&(b=='\0'))
                            return -1;
    for(i=0;i<6;i++)
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

void inorder(node *curr)
{
 	if(curr->left!=NULL)
   	 inorder(curr->left);
   printf("%c ",curr->data);
 	if(curr->right != NULL)
   	 inorder(curr->right);
}

int main()
{
    stack optor_val;
    stack2 nodes,opand_node;
    int ch=0,l,i,count=0;
    char exp[100],c,d=' ',e;
    node *x,*y,*z,*root;

    printf("-----------------------------------------------------------------\n\n");
    printf(" Program to create an expression tree and traverse it in Inorder");
    printf("\n\n-----------------------------------------------------------------\n\n");


    initialize(&optor_val,50);
    initialize2(&nodes,50);
    initialize2(&opand_node,50);        
    
    printf("\nEnter the Infix expression: ");
    gets(exp);

    l=strlen(exp);

    for(i=0;i<=l;i++)
    {
             c=exp[i];

             if(((c>='(')&&(c<='/'))||(c=='^'))  //Operator or brackets
             {
                       if(c=='(')
                                 push(&optor_val,c);


                       else if(c==')')
                       {
                            d=optor_val.a[optor_val.top];
                            while(d!='(')
                            {
                                         e=pop(&optor_val);
                                         x=(node *)malloc(sizeof(node));
                                         x->data=e;                                         
                                         x->left=*(pop2(&nodes));
                                         x->right=*(pop2(&nodes));
                                         push2(&nodes,&x);
                                         d=optor_val.a[optor_val.top];
                            }
                            e=pop(&optor_val);
                       }

                       else
                       {
                                   if(optor_val.top>=0)
                                       d=optor_val.a[optor_val.top];

                                   if(highpreccheck(c,d))
                                   {
                                       push(&optor_val,c);
                                   }
                                   else
                                   {
                                       while(highpreccheck(c,d)==0)
                                       {
                                             e=pop(&optor_val);
                                             x=(node *)malloc(sizeof(node));
                                             x->data=e;                                         
                                             x->right=*(pop2(&nodes));
                                             x->left=*(pop2(&nodes));
                                             push2(&nodes,&x);
                                             if(optor_val.top>=0)
                                                  d=optor_val.a[optor_val.top];
                                             else
                                                 d=' ';
                                       }
                                       push(&optor_val,c);
                                   }
                       }
             }

             else if(c!=0)       //Operand
             {
                 y=(node *)malloc(sizeof(node));
                 y->data=c;                                         
                 y->left=NULL;
                 y->right=NULL;
                 
                 push2(&nodes,&y);
             }

             else if(c==0)        //Sentinel
             {
                 while((optor_val.top)>=0)
                 {
                           z=(node *)malloc(sizeof(node));
                           z->data=pop(&optor_val);                                         
                           z->right=*(pop2(&nodes));
                           z->left=*(pop2(&nodes));
                 
                           push2(&nodes,&z);
                 }
             }    
    }
             
    root=*(pop2(&nodes));
    
    printf("\nThe infix traversal of the expression tree is: \n");
    inorder(root);
    
    getch();
    return 0;
}
