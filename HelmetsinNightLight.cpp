#include<bits/stdc++.h>
using namespace std;
typedef long  long ll;

ll min(ll a,ll b){
    return (a<b) ? a : b;
}
int main(){
    int t; 
    cin>>t;
    while(t--){
        ll n,p;
        ll info = 1;
        cin>>n>>p;
        ll cost = p;
        vector<pair<ll,ll>> a(n);
        for(ll i = 0; i < n; i++) cin>>a[i].second;
        for(ll i = 0; i < n; i++) cin>>a[i].first;
        sort(a.begin(),a.end());
        for(auto [f,s] : a){
            if(f>p) break;
            cost += f*min(s,n-info);
            info += min(s,n-info);
        }
        cost += (n - info)*p;
        cout<<cost<<endl;
        
    }
    return 0;
}