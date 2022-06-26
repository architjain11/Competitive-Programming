#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%li", &t);
    while(t--)
    {
        char n[19];
        scanf("%s", &n);
        int sum=0;
        for(int i=0; n[i]!='\0'; i++)
            sum=sum+n[i]-'0';
        sum=(10-sum%10)%10;
        printf("%s%i\n", n, sum);
    }
    return 0;
}