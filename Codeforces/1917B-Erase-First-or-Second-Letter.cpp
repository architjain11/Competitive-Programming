#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        set<char> s;
        int ans=0;

        while(n--) {
            char a; cin>>a;
            s.insert(a);
            ans+=s.size();
        }

        cout<<ans<<endl;
    }

    return 0;
}