#include<stdio.h>
#include<math.h>

int main(void)
{

	int t;
    scanf("%i", &t);
    if(t>512 || t<1)
        return 0;
    for(int q=0; q<t; q++)
    {
        int r, c, k, count=0;
        scanf("%i %i %i", &r, &c, &k);
        if(r>8 || c>8 || k>8 || r<1 || c<1 || k<1)
            return 0;

        for(int i=1; i<9; i++)
            for(int j=1; j<9; j++)
                if(pow((r-i),2)<=pow(k,2) && pow((c-j),2)<=pow(k,2))
                    count++;
        printf("%i\n", count);
    }
	return 0;
}