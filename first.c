#include<stdio.h>

enum WEEK{
    sun=100,mon,tue,wed,thu,fri,sat // by default the value is assign by 0 but you can also assign as u required
};

void main()
{
    enum WEEK today;
    today=mon;
    printf("Today Is : %d",today);
}