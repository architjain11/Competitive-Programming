#include <stdio.h>

#define n_limit 10000

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n, arr[n_limit];
        scanf("%i", &n);
        for (int i = 0; i < n; i++)
            scanf("%i", &arr[i]);

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                int value;
                if (arr[j] < arr[i])
                {
                    value = arr[i];
                    arr[i] = arr[j];
                    arr[j] = value;
                }
            }

        int flag = 0;
        long int p1 = 0, p2 = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (flag == 0)
            {
                if (i == n - 3)
                    p2 += arr[i];
                else
                {
                    p1 += arr[i];
                    flag++;
                }
            }
            else if (flag == 1)
            {
                p2 += arr[i];
                flag--;
            }
        }

        if (p1 > p2)
            printf("first\n");
        else if (p1 < p2)
            printf("second\n");
        else
            printf("draw\n");
    }
    return 0;
}