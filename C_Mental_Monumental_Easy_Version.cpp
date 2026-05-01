/*
    Author: Tonoy39
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

#define pb push_back
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

/* ---------- GCD & LCM ---------- */
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/* ---------- Binary Power ---------- */
ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

/* ---------- Power without mod ---------- */
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

/* ---------- Prime Check ---------- */
bool isPrime(ll n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

/* ---------- Sieve ---------- */
vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}

/* ---------- Prime Factorization ---------- */
vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.pb(i);
            n /= i;
        }
    }
    if (n > 1) factors.pb(n);
    return factors;
}

/* ---------- Divisors ---------- */
vector<ll> divisors(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);
            if (i != n / i)
                divs.pb(n / i);
        }
    }
    return divs;
}

/* ---------- Modular Inverse ---------- */
ll modInverse(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

/* ---------- nCr ---------- */
const int MAX = 200000;
ll fact[MAX], invfact[MAX];

void init_nCr() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

bool isPerfectSquare(ll x) {
    ll s = sqrt(x);
    return s * s == x;
}

bool check(int m, vector<int>& a){
    vector<int> need(m,1);
    vector<int> have, uf;
    //jegulare convert korte parbo segula ber kori 
    for(int x : a){
        if(x < m && need[x]){
            need[x] = 0;
        }
        else have.push_back(x);
    }
    //jeshobe convert korte hobe
    for(int i = 0; i < m; i++){
        if(need[i]) uf.push_back(i);
    }
    // to ekhane req = have[p]%b  --> q*b + req = have[p] mini have[p] er jonno q = 1  req < b   req* 2 + 1 <= have hoile b ache ar req pabo
    int k = 0;
    for(int req : uf){
        while(k < have.size() && have[k] < req*2 + 1) k++;
        if(k == have.size()) return false;
        k++;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int& i : a) cin>>i;

    sort(all(a));

    int l = 0, h =  n;
    int mx = 0;
    while(l <= h){
        int mid = l + (h - l)/2;
        if(check(mid, a)){
            mx = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }

    cout<<mx<<endl;
}

int main() {
    fastio;

    // init_nCr();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}