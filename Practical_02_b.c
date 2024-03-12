#include<stdio.h>
#define PI 3.14
#define Benny// define the conditional compilation

int main()
{   float r,res,D;
    printf("Enter the Value of Radius of circle :\n");
    scanf("%f",&r);

    #ifdef Benny
    res=PI*r*r;
    printf("Area of The Circle is : %f\n",res); // compile only if it is define okay
    #endif
 
    D=2*r;
    printf("Diameter of The circle is: %f",D);
    return 0;
}