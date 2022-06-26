#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,b,out;
    cin>>a>>b;
    for(int i=0; i<a.length(); i++) {
        if(a[i]==b[i])
            out.append("0");
        else
            out.append("1");
    }
    cout<<out;
    return 0;
}