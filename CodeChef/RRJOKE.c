#include<stdio.h>

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        int n, x, y, output=0;
        scanf("%i", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%i%i", &x, &y);
            output = output^i;
        }
        printf("%i\n", output);
    }
    return 0;
}