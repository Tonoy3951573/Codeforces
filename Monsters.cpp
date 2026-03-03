#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        vector<pair<long long int,long long int>> a(n);
        
        for(long long int i = 0; i < n; i++){
            cin>>a[i].first;
            a[i].first %= k;
            if(a[i].first == 0) a[i].first = k;
            a[i].second = i;
        }

        sort(a.begin(),a.end(),[&](pair<long long, long long> a, pair<long long, long long> b) {
			if (a.first != b.first)
				return a.first > b.first;
			return a.second < b.second;
		});

        for(auto [f,s] : a){
            cout<<s+1<<" ";
        }
        cout<<endl;
    }
}