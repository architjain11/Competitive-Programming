#include<stdio.h>

int sum_of_digits(int num)
{
    int sum=0;
    do
    {
        sum+=num%10;
        num/=10;
    }while(num!=0);
    return sum;
}

int main()
{
    int t;
    scanf("%i", &t);

    while(t--)
    {
        int N;
        scanf("%i", &N);
        int chef=0, morty=0;

        while(N--)
        {
            int c, m;
            scanf("%i", &c);
            scanf("%i", &m);

            if(sum_of_digits(c)!=sum_of_digits(m))
                sum_of_digits(c)>sum_of_digits(m)?chef++:morty++;
            else
            {
                chef++;
                morty++;
            }
        }
        if(chef!=morty)
            chef>morty?printf("0 %i\n", chef):printf("1 %i\n", morty);
        else
            printf("2 %i\n", chef);
    }
    return 0;
}   