#include<stdio.h>

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        unsigned long long int a, b;
        int n;
        scanf("%llu%llu%i", &a, &b, &n);
        if(n%2!=0)
            a*=2;
        printf("%llu\n", a>b?a/b:b/a);
    }
    return 0;
}