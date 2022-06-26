#include <iostream>

#define N 100000
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int a[N], n, max=0, min=100001;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]>max)
                max=a[i];
            if(a[i]<min)
                min=a[i];
        }            

        cout<<max-min<<endl;
    }
    return 0;
}