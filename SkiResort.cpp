#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
        freopen("input.txt", "r", stdin);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n);
        for(int &i : a) cin >> i;

        long long ans = 0, count = 0; 
        for(int i = 0; i < n; i++){
            if(a[i] > q){
                if(count >= k){
                    long long p = count - k + 1;
                    ans +=  (p + 1) * p / 2;
                }
                count = 0;
            } else count++;
        }
        if(count >= k){
            long long  p = count - k + 1;
            ans += (p + 1) * p / 2;
        }
        cout << ans << endl;
    }
}
