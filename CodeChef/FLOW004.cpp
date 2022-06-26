#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, sum=0;
        cin>>n;
        sum+=n%10;
        while(n>=10)
            n/=10;
        sum+=n;
        cout<<sum<<endl;
    }
    return 0;
}