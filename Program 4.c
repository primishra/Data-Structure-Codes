/*
Program 4:
        Program to implement sparse matrix representaion.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int **a,**b,r,c,i,j,count=0,x=1;
    
    printf("---------------------------------------------------\n\n");
    printf(" Program to implement sparse matrix representation");
    printf("\n\n---------------------------------------------------\n\n");
    
    printf("\nEnter the dimensions of the original matrix: ");
    scanf("%d%d",&r,&c);
    
    a=(int **)malloc(r*sizeof(int *));
    for(i=0;i<r;i++)
                    a[i]=(int *)malloc(c*sizeof(int));
    
    printf("\nEnter the elements of the original matrix A: \n");
    for(i=0;i<r;i++)
    {
                    for(j=0;j<c;j++)
                    {
                                    scanf("%d",&a[i][j]);
                                    if(a[i][j]!=0)
                                                  count++;
                    }
    }
    
    b=(int **)malloc((count+1)*sizeof(int *));
    for(i=0;i<(count+1);i++)
                            b[i]=(int *)malloc(3*sizeof(int));
                            
    b[0][0]=count;
    b[0][1]=r;
    b[0][2]=c;
    
    for(i=0;i<r;i++)
    {
                    for(j=0;j<c;j++)
                    {
                                    if(a[i][j]!=0)
                                    {
                                                  b[x][0]=a[i][j];
                                                  b[x][1]=i+1;
                                                  b[x][2]=j+1;
                                                  x++;
                                    }
                    }
    }
    
    printf("\n\nOriginal matrix A: \n");
    for(i=0;i<r;i++)
    {
                    for(j=0;j<c;j++)
                    {
                                    printf("%d ",a[i][j]);
                    }
                    printf("\n");
    }
    
    printf("\n\nSparse Matrix B: \n");
    for(i=0;i<(count+1);i++)
    {
                            for(j=0;j<3;j++)
                            {
                                            printf("%d ",b[i][j]);
                            }
                            printf("\n");
    }
    
    getch();
    return 0;
}
                            
