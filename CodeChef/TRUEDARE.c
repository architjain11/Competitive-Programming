#include<stdio.h>

#define limit 100

int ele_in_arr(int ele, int arr[], int arr_size);

int main()
{
    int t;
    scanf("%i", &t);
    while(t--)
    {
        int n1, n2, n3, n4, t1[limit], t2[limit], d1[limit], d2[limit];
        scanf("%i", &n1);
        for(int j=0; j<n1; j++)
            scanf("%i", &t1[j]);
        scanf("%i", &n2);
        for(int j=0; j<n2; j++)
            scanf("%i", &d1[j]);
        scanf("%i", &n3);
        for(int j=0; j<n3; j++)
            scanf("%i", &t2[j]);
        scanf("%i", &n4);
        for(int j=0; j<n4; j++)
            scanf("%i", &d2[j]);

        int flag=0;
        for(int i=0; i<n3; i++)
            if(ele_in_arr(t2[i], t1, n1)==0)
            {
                flag=1; //Shyam wins
                break;
            }
        for(int i=0; i<n4; i++)
            if(ele_in_arr(d2[i], d1, n2)==0)
            {
                flag=1; //Shyam wins
                break;
            }
        if(flag==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

int ele_in_arr(int ele, int arr[], int arr_size)
{
    for(int i=0; i<arr_size; i++)
        if(ele==arr[i])
            return 1;
    return 0;
}