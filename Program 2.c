/*
Program 2:
        Program to add and subtract two polynomials using array.
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    int **p1,**p2,**p3,maxx,maxy,i,j,ch;
    
    printf("------------------------------------------\n\n");
    printf(" Program to add or subtract 2 polynomials");
    printf("\n\n------------------------------------------\n\n");
    
    printf("\nEnter maximum powers of x and y in either polynomial: ");
    scanf("%d%d",&maxx,&maxy);
    maxx++;maxy++;
    
    p1=(int **)malloc(maxx*sizeof(int *));
    for(i=0;i<maxx;i++)
    {
                        p1[i]=(int *)malloc(maxy*sizeof(int));
    }
    
    p2=(int **)malloc(maxx*sizeof(int *));
    for(i=0;i<maxx;i++)
    {
                        p2[i]=(int *)malloc(maxy*sizeof(int));
    }
    
    p3=(int **)malloc(maxx*sizeof(int *));
    for(i=0;i<maxx;i++)
    {
                        p3[i]=(int *)malloc(maxy*sizeof(int));
    }
    
    printf("\nPolynomial 1: \n");
    
    printf("\n\nEnter co-efficients: \n");
    for(i=maxx-1;i>=0;i--)
    {
                       for(j=maxy-1;j>=0;j--)
                       {
                                          printf("x^%dy^%d: ",i,j);
                                          scanf("%d",&p1[i][j]);
                                          printf("\n");
                       }
    }
    
    printf("\nEntered polynomial: \nP1= ");
    for(i=maxx-1;i>=0;i--)
    {
                       for(j=maxy-1;j>=0;j--)
                       {
                                               
                                               if(p1[i][j]==0)
                                                              break;
                                                   else if(p1[i][j]>1)
                                                              printf("%d",p1[i][j]);
                                                   if(i>1)
                                                              printf("x^%d",i);
                                                   else if(i==1)
                                                              printf("x");
                                                   if(j>1)
                                                              printf("y^%d",j);
                                                   else if(j==1)
                                                              printf("y");
                                               if((p1[i][j]==1)&&(i==0)&&(j==0))
                                                   printf("1");
                                               printf(" + ");
                       }
    }
    printf("0 \n");
    
    printf("\nPolynomial 2: \n");
    
    printf("\n\nEnter co-efficients: \n");
    for(i=maxx-1;i>=0;i--)
    {
                       for(j=maxy-1;j>=0;j--)
                       {
                                          printf("x^%dy^%d: ",i,j);
                                          scanf("%d",&p2[i][j]);
                                          printf("\n");
                       }
    }
    
    printf("\nEntered polynomial: \nP2= ");
    for(i=maxx-1;i>=0;i--)
    {
                       for(j=maxy-1;j>=0;j--)
                       {
                                               if(p2[i][j]==0)
                                                              break;
                                                   else if(p2[i][j]>1)
                                                              printf("%d",p2[i][j]);
                                                   if(i>1)
                                                              printf("x^%d",i);
                                                   else if(i==1)
                                                              printf("x");
                                                   if(j>1)
                                                              printf("y^%d",j);
                                                   else if(j==1)
                                                              printf("y");
                                               if((p2[i][j]==1)&&(i==0)&&(j==0))
                                                   printf("1");
                                               printf(" + ");
                       }
    }
    printf("0 \n");
    
    printf("\n\n1.Press 1 to add the 2 polynomials.");
    printf("\n2.Press 2 to subtract polynomial 2 from 1.");
    printf("\nEnter choice: ");
    scanf("%d",&ch);
    
    for(i=0;i<maxx;i++)
    {
                       for(j=0;j<maxy;j++)
                       {
                                          switch(ch)
                                          {
                                                    case 1:
                                                         p3[i][j]=p1[i][j]+p2[i][j];
                                                         break;
                                                    case 2:
                                                         p3[i][j]=p1[i][j]-p2[i][j];
                                                         break;
                                                    default:
                                                            printf("Wrong choice entered");
                                                            ch=0;
                                          }
                       }
    }
    
    if(ch!=0)
    {
             printf("\nFinal result: \nP3= ");
             for(i=maxx-1;i>=0;i--)
             {
                        for(j=maxy-1;j>=0;j--)
                                 {
                                              if(p3[i][j]==0)
                                                              break;
                                                   else if(p3[i][j]>1)
                                                              printf("%d",p3[i][j]);
                                                   if(i>1)
                                                              printf("x^%d",i);
                                                   else if(i==1)
                                                              printf("x");
                                                   if(j>1)
                                                              printf("y^%d",j);
                                                   else if(j==1)
                                                              printf("y");
                                              if((p3[i][j]==1)&&(i==0)&&(j==0))
                                                   printf("1");
                                               printf(" + ");
                                 }
             }
             printf("0 \n");
    }
    
    getch();
    return 0;
}
             
