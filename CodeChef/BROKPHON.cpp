#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> a;
	    for(int i=0; i<n; i++) {
	        int c;
	        cin>>c;
	        a.push_back(c);
	    }
	    int ans=0, flag=0;
	    for(int i=1; i<n; i++) {
            if(a[i]!=a[i-1]) {
                if(flag==0) {
                    ans+=2;
                    flag=1;
                }
                else ans+=1;
                continue;
            }
            flag=0;
	    }
	    cout<<ans<<endl;	    
	}
	return 0;
}