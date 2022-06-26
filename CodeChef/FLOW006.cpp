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
        for(; n!=0; n/=10)
            sum+=n%10;
        cout<<sum<<endl;
    }
    return 0;
}