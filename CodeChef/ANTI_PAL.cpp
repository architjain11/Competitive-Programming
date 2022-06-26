#include<bits/stdc++.h>

using namespace std;

int findDiff(string &s, int index) {
    int len = s.length();
    for(int i=0; i<len/2; i++) {
        if(s[len-i-1]!=s[index] && s[i]!=s[index]) {
            char temp = s[i];
            s[i] = s[index];
            s[index] = temp;
            return 0;
        }
    }
    return 1;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        if(n%2==0) {
            bool y = true;
            for(int i=0; i<n/2; i++) {
                if(s[i] == s[n-i-1]) {
                    int flag = findDiff(s, i);
                    if(flag==1) {
                        cout<<"NO"<<endl;
                        y = false;
                        break;
                    }
                }
            }
            if(y==true)
                cout<<"YES"<<endl<<s<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}