#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        map<ll, ll> m;
        ll ans=0;

        for(ll i=0; i<n; ++i) {
            ll x; cin>>x;
            x-=i;
            if(m.count(x))
                ans+=m[x];
            m[x]++;
        }

        cout<<ans<<endl;
    }

    return 0;
}