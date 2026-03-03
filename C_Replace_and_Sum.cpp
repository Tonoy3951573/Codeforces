/*
Tonoy39
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

// Fast Power (Binary Exponentiation)
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// GCD
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Check Prime
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void solve() {
    int n,q;
    cin>>n>>q;

    vector<long long> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<long long> best(n);
    for(int i = 0; i < n; i++){
        best[i] = max(a[i], b[i]);
    }

    vector<long long> suf(n);
    suf[n-1] = best[n-1];
    
    for(int i = n-2; i >= 0; i--){
        suf[i] = max(best[i], suf[i+1]);
    }

    vector<long long> presum(n+1,0);
    for(int i = 0; i < n; i++){
        presum[i+1] = presum[i] + suf[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        cout << presum[r] - presum[l-1] << " ";
    }
    cout << "\n";
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}