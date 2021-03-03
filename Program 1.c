/*
Program 1:
        Program to create a one dimensional array at run time with user given number of elements in it,
        with separate functions that allow insertion and deletion of elements into/from this array at any arbitrary location.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void show(int *,int);
int * create(int *,int);
void insert(int *,int *,int);
void delete(int *,int *);
     
int main()
{
	int *arr,ch=0,size,max,i;
	
	printf("--------------------------------------------\n\n");
    printf(" Program to create a 1-D array at runtime, \n To implement insertion and deletion in it.");
    printf("\n\n--------------------------------------------\n\n");
    
    printf("\nEnter the maximum no. of elements in the array: ");
	scanf("%d",&size);
    
    
    arr=create (arr,size);
	
	printf("\nEnter the no. of elements to input in the array: ");
	scanf("%d",&max);
	printf("\nEnter the %d elements: \n",max);
	for(i=0;i<max;i++)
	{
		scanf("%d",(arr+i));	
	}
	
	printf("Array at the end of input: \n");
	show(arr,max);
	
    while(ch!=3)
	{
		printf("\n\n1.Press 1 to insert new elements");
		printf("\n2.Press 2 to delete existing elements");
		printf("\n3.Press 3 to print final array and exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insert(arr,&max,size);
                break;
            
            case 2:
                 delete(arr,&max);
                 break;
            case 3:
                 show(arr,max);
                 break;
            default:
                 printf("\nWrong choice entered");
         }    
    
        
    }
    
    getch();
    return 0;
}

void show(int *a,int max)
{
     int i;
     for(i=0;i<max;i++)
                       printf("%d ",*(a+i));
     printf("\n");
}

int * create(int *a,int size)
{
	a=(int *)malloc(size*sizeof(int));	
    return a;
}

void insert(int *a,int *max,int size)
{
	int n,i,pos,elem,j;
	

    
    printf("\nEnter the no. of elements to be inserted: ");
	scanf("%d",&n);
	
	if((*max+n)>size)
	{
		printf("\nOverflow");
		return;
	}	
    
    else
    {
        for(i=1;i<=n;i++)
        {
                         printf("\nEnter position: ");
                         scanf("%d",&pos);
                         printf("\nEnter element to be inserted: ");
                         scanf("%d",&elem);
                         for(j=*max;j>=pos;j--)
                         {
                                                 *(a+j)=*(a+j-1);
                         }
                         *(a+pos-1)=elem;
                         (*max)++;
        }
    }
    
    printf("\nArray at the end of insertion: \n");
    show(a,*max);                      
}

void delete(int *a,int *max)
{
     int n,i,pos,j;
     printf("\nEnter the no. of elements to be deleted: ");
     scanf("%d",&n);
     
     if(n>*max)
               printf("\nUnderflow");
     
     else
     {
         for(i=1;i<=n;i++)
         {
                          printf("\nEnter position to be deleted: ");
                          scanf("%d",&pos);
                          for(j=pos-1;j<*max-1;j++)
                                                   *(a+j)=*(a+j+1);
                          (*max)--;
         }
     }
     
     printf("\nArray at the end of deletion: \n");
     show(a,*max);
}
