#include <stdio.h>

int main()
{
    puts("This is a software to Find the Sum of any 2 number");
    int num1;
    int num2;
    printf("Input the 1st Number: ");
    scanf("%d",&num1);

    printf("Input the 2nd Number: ");
    scanf("%d",&num2);

    printf("%d + %d = %d",num1,num2,num1+num2);
    return 0;
}