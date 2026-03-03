#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> price(n), max_pay(m);
    for (int &i : price) cin >> i;
    for (int &i : max_pay) cin >> i;

    sort(price.begin(), price.end());

    for (int i = 0; i < m; i++) {
        auto pos = upper_bound(price.begin(), price.end(), max_pay[i]);

        if (pos == price.begin()) {
            cout << -1 << '\n';
        } else {
            --pos;
            cout << *pos << '\n';
            price.erase(pos);
        }
    }
}
