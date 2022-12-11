#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    int n,x;
	    cin>>n>>x;
	    int maxr=INT_MIN;
	    while(n--) {
	        int s,r;
	        cin>>s>>r;
	        if(s<=x) maxr=max(maxr, r);
	    }
	    cout<<maxr<<endl;
	}
	return 0;
}