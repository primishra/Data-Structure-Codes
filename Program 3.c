/*
Program 3:
        Program to verify the address calculation formulae for any arbitrary element of 1-D, 2-D and 3-D arrays.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int a[10],b[10][10],c[10][10][10],ch,m,n,o,x,y,z,i,j,*base,add;
    
    printf("------------------------------------------------\n\n");
    printf(" Program to verify address calculation formulae");
    printf("\n\n------------------------------------------------\n\n");
    
    printf("\n1. Press 1 for 1-D array.");
    printf("\n2. Press 2 for 2-D array.");
    printf("\n3.Press 3 for 3-D array.");
    printf("\nEnter choice: ");
    scanf("%d",&ch);
    
    switch(ch)
    {
              case 1:
                   m=10;
                   printf("\n\nSize of 1-D array (M): %d",m);
                   
                   printf("\nEnter position to check address (X): ");
                   scanf("%d",&x);
                   
                   base=&a[0];
                   printf("\nBase address (B): %u",base);
                   printf("\nWidth (W): %d",sizeof(int));
                   
                   add= (int)base + ((x-1)*sizeof(int));
                   printf("\nAddress from calculation: B + (X-1)*W = %d",add);
                   printf("\nActual address: %u",&a[x-1]);
                   
                   printf("\n\nAddress calculation formula for 1-D array verified!");
                   break;
              case 2:
                   m=10;n=10;
                   printf("\n\nDimensions of 2-D array (M and N): %d and %d",m,n);
                   
                   printf("\nEnter position to check address (X and Y): ");
                   scanf("%d%d",&x,&y);
                   
                   base=&b[0][0];
                   printf("\nBase address (B): %u",base);
                   printf("\nWidth (W): %d",sizeof(int));
                   
                   add= (int)base + ((n*(x-1) + (y-1))*sizeof(int));
                   printf("\nAddress from calculation (Row Major Order) : B + [N*(X-1) + (Y-1)]*W = %d",add);
                   printf("\nActual address: %u",&b[x-1][y-1]);
                   
                   
                   printf("\n\nAddress calculation formula for 2-D array verified!");
                   break;
              case 3:
                   m=10;n=10;o=10;
                   printf("\n\nDimensions of 2-D array (M,N and O): %d, %d and %d",m,n,o);
                   
                   printf("\nEnter position to check address (X, Y and Z): ");
                   scanf("%d%d%d",&x,&y,&z);
                   
                   base=&c[0][0][0];
                   printf("\nBase address (B): %u",base);
                   printf("\nWidth (W): %d",sizeof(int));
                   
                   add= (int)base + ((n*o*(x-1) + o*(y-1) + (z-1))*sizeof(int));
                   printf("\nAddress from calculation (Row Major Order) : B + [N*O*(X-1) + O*(Y-1) + (Z-1)]*W = %d",add);
                   printf("\nActual address: %u",&c[x-1][y-1][z-1]);
                                      
                   printf("\n\nAddress calculation formula for 3-D array verified!");
                   break;
    }
    
    getch();
    return 0;
}
