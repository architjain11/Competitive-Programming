#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    for(int i=n; i>0; i--) {
        for(int j=0; j<i-1; j++)
            cout<<" ";
            
        if(i==n || i==1)
            for(int j=0; j<n; j++)
                cout<<"*";
        else {
            for(int j=0; j<n; j++){
                if(j==n-1 || j==0)
                    cout<<"*";
                else
                    cout<<" ";
            }
        }
        cout<<endl;
    }

}