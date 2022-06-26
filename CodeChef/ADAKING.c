#include <stdio.h>
int main(void)
{
    int K,T,k,i,j,C[8][8],q;
    scanf("%i",&T);
    for(k=0;k<T;k++)
    {

        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
                C[i][j]=0;
        scanf("%i",&K);
        q=0;
        if(K==1)
            goto abc;
        for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(i==0&&j==0)
                        j++;
                    C[i][j]=1;
                    q++;
                    if(q==K-1)
                        goto abc;
                }
            }

        abc:
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
                {
                    if(i==0&&j==0)
                        printf("O");
                    else if(C[i][j]==0)
                        printf("X");
                    else
                        printf(".");
                }
            printf("\n");
        }
    }
    return 0;
}