#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    int u,v,a,s;
	    cin>>u>>v>>a>>s;
	    if(pow(v,2)>=pow(u,2)-2*a*s) cout<<"yes";
	    else cout<<"no";
	    cout<<endl;
	}
	return 0;
}