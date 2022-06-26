#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a[6];
        for(int i=0; i<6; i++)
            cin>>a[i];
        
        int votes_required = (a[3]+a[4]+a[5])/2;
        int index, max=0;

        for(int i=0; i<3; i++) {
            if(a[i+3]-a[i]>max) {
                index = i;
                max = a[i+3]-a[i];
            }
        }

        int votes = 0;
        for(int i=0; i<3; i++) {
            if(i==index)
                votes+=a[i+3];
            else
                votes+=a[i];
        }

        cout<<(votes>votes_required?"YES":"NO")<<endl;

    }
    return 0;
}