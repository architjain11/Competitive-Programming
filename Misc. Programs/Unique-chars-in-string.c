#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//To find whether a string has all unique characters
int main()
{
    char *a=malloc(50);
    scanf("%s", a);
    
    for(int i=0, n=strlen(a); i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[i]==a[j])
            {
                printf("All characters in string not unique");
                free(a);
                return 1;
            }
    printf("All characters in string are unique");
    free(a);
}


