#include<stdio.h>
#define Area
#define PI 3.14159
#define AreaRec

void main()
{
    printf("\n enter the redius to get area of circle\n");
    int r;
    scanf("%d", &r);


    #ifdef Area
    int res=PI*r*r;
    printf("Area of circle is : %d\n", res);
    #endif

    #ifdef AreaRec
    printf("To find the area of rectangle enter the length and breadth of the rectangle ");
    int l,b;
    scanf("%d", &l);
    scanf("%d", &b);
    int recRes=l*b;
    printf("Area of rectangle is : %d\n", recRes);
    #endif


    

}
