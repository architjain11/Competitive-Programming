#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;

    while(t--) {
        int n, k;
        cin>>n>>k;

        int x = (k/(n-1));
        if((x+k)%n == 0)
            cout<<x+k-1<<endl;
        else
            cout<<x+k<<endl;
    }

    return 0;
}