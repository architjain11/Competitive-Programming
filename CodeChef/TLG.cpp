#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    pair<int, int> ans={0,0};
    int p1, p2, cumulative1=0, cumulative2=0;
    for(int i=0; i<n; i++) {
        cin>>p1>>p2;
        cumulative1+=p1;
        cumulative2+=p2;
        int lead=cumulative1-cumulative2;

        if(lead>0 && lead>ans.second) ans={1, lead};
        else if(lead<0 && -1*lead>ans.second) ans={2, -1*lead};
    }
    cout<<ans.first<<" "<<ans.second;
    return 0;
}