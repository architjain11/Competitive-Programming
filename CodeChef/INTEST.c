#include<stdio.h>

int main()
{
    int n, k, t;
    scanf("%i%i", &n, &k);
    int num = 0;
    while(n--)
    {
        scanf("%i", &t);
        if(t%k==0)
            num++;
    }
    printf("%i\n", num);
}