#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--) {
	    int n; cin>>n;
	    vector<int> heights(n);
	    map<int, int> m;
	    
	    for(auto& height: heights) {
	        cin>>height;
	        m[height]++;
	    }
	    
	    int ans=INT_MIN;
	    for(auto a: m)
	        ans=max(ans, a.first+a.second-1);
	    
	    cout<<ans<<endl;
	    
	}
	return 0;
}