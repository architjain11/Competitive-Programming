#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin>>str;
    sort(str.begin(), str.end());

    int distinct=1;
    for(int i=1; i<str.length(); i++) {
        if (str[i]!=str[i-1])
            distinct++;
    }

    cout<<distinct<<endl;
    if (distinct%2==0)
        cout<<"CHAT WITH HER!";
    else
        cout<<"IGNORE HIM!";
    return 0;
}