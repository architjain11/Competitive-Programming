#include <stdio.h>

#define n_range 100000

int main()
{

	int t;
    scanf("%i", &t);
    for(int q=0; q<t; q++)
    {
        long int a[n_range], n, count=0;
        scanf("%li", &n);
        for(int i=0; i<n; i++)
            scanf("%li", &a[i]);

        for(int i=0; i<n-1; i++)
        {
            int diff=a[i]!=a[i+1] ? ((a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i])-1) : 0;
            count+=diff;
        }
        printf("%li\n", count);
    }
	return 0;
}