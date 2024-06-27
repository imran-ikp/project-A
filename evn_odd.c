#include<stdio.h>
main()
{
    int num;
    printf("enter num");
    scanf("%d",num);
    if(num % 2==0)
    {
        printf("even");
    }
    else
    {
        printf("odd");
    }
}