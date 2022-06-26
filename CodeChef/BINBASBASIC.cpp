#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        string s;
        cin>>n>>k>>s;

        for(int i=0; i<n/2; i++)
            if(s[i]!=s[n-1-i])
                k--;

        if(k>=0) {
            if(n%2!=0 || k%2==0)
                cout<<"YES";
            else
                cout<<"NO";
        }
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}