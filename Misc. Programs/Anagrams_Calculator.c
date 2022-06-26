#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//To count the number of anagrams of a given word.
int fact(int x)
{
    if(x>1)
        return x*fact(x-1);
    else
        return 1;
}

int main()
{
    char *string=malloc(100);
    scanf("%s", string);

    int numofletters[26];
    /* Each element of this array represents one letter out of the 26 letters in the alphabet
    series and has the count of the number of times it is repeated in the given string. */
    for(int i=0; i<26; i++)
        numofletters[i]=0;

    for(int i=0, n=strlen(string); i<n; i++)
        numofletters[string[i]-97]++;

    int denominator=1;
    for(int i=0; i<26; i++)
        denominator*=fact(numofletters[i]);

    //Formula for num of anagrams = n! / (p! * q! * r!...)
    int anagrams=fact(strlen(string)) / denominator;
    printf("The total number of anagrams= %i", anagrams);
    free(string);
}


