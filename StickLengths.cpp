#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());
    long long median = a[n / 2]; 

    long long ans = 0;
    for (auto x : a)
        ans += llabs(x - median);

    cout << ans << "\n";
    return 0;
}
