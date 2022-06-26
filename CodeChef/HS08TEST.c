#include<stdio.h>

int main()
{
    int withdraw;
    float balance;
    scanf("%i%f", &withdraw, &balance);
    if(withdraw+0.5<=balance && withdraw%5 == 0)
        balance -= withdraw+0.5;
    printf("%.2f\n", balance);
    return 0;
}