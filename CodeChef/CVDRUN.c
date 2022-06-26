#include<stdio.h>

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        int info[4];
        for(int i=0; i<4; i++)
            scanf("%i", &info[i]);

        int newcity, flag=1;
        int original = info[2]; 
        do
        {
            newcity = (info[1]+info[2])%info[0];
            info[2] = newcity;
            if(newcity == info[3])
            {
                printf("YES\n");
                flag = 0;
                break;
            }            
        } while (newcity != original);
        if(flag==1)
            printf("NO\n");
    }
    return 0;
}