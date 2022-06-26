#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        int len, zero=0, one=0;
        cin>>len>>s;
        for(int i=0; i<len; i++)
            s[i]=='0'?zero++:one++;
        cout<<(zero==one?2*zero:(zero>one?2*one+1:2*zero+1))<<endl;
    }
    return 0;
}