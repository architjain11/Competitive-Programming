#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    long int n,k;
	    cin>>n>>k;
	    cout<<(k==0?n:n%k)<<endl;
	}
	return 0;
}