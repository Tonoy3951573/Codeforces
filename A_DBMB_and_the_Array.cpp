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
    int n, s, x;
    cin>>n>>s>>x;
    vector<int> a(n);
    for(int& i : a) cin>>i;

    int sum = 0;
    for(int i : a) sum += i;
    int d =  s - sum;
    if(d >= 0 && d%x == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}