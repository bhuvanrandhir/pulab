#include<stdio.h>
int main()
{
    printf("Current System Time : %s\n",__TIME__);
    printf("Current Date According to the system is: %s\n",__DATE__);
    printf("Current line where you work now:%d\n",__LINE__);
    printf("Current File Name: %s\n",__FILE__);
    return 0;

}