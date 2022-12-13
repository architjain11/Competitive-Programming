#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    int h,x,y,c;
        cin>>h>>x>>y>>c;
        if((x+(y/2))*h<=c) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
	}
	return 0;
}
