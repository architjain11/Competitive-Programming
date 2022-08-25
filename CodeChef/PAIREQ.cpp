#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> arr;
        for(int i=0; i<n; i++) {
            int ele;
            cin>>ele;
            arr.push_back(ele);
        }
        
        map<int, int> m;
        for(auto x: arr) m[x]++;
        
        int occurMax=INT_MIN;
        for(auto x: m) 
            occurMax=max(occurMax, x.second);
            
        cout<<n-occurMax<<endl;
	}
	return 0;
}
