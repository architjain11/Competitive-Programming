#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;

    int n; cin>>n;
    while(n--) {
        string team; cin>>team;
        m[team]++;
    }
    auto maxIter=max_element(m.begin(), m.end(),
        [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second < p2.second;
        });
    cout<<maxIter->first<<endl;
    return 0;
}