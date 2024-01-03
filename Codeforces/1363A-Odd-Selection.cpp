#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n, x; cin>>n>>x;
        int odd=0, even=0;

        for(int i=0; i<n; ++i) {
            int a; cin>>a;
            if(a%2==0) even++;
            else odd++;
        }
        
        int a=x-min(even, x-1);
        if(a%2==0) a++;
        if(odd>=a && a<=x) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}