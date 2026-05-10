
/*
    Author: Tonoy39
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(ifstream &in, ofstream &out) {
    int n, m;
    cin >> n >> m;

    char A = 'G', B = 'B';
    int a = n, b = m;

    if (m > n) {
        swap(a, b);
        swap(A, B);
    }

    int groups = b + 1;

    vector<int> slots(groups, 0);

    for (int i = 0; i < a; i++) {
        slots[i % groups]++;
    }

    string res = "";
    for (int i = 0; i < groups; i++) {
        res += string(slots[i], A);
        if (i < b) res += B;
    }

    cout << res << '\n';
}

int main() {
    fastio;

    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in) {
        cerr << "Error: input.txt not found\n";
        return 0;
    }

    int t = 1;
    // in >> t;

    while (t--) {
        solve(in, out);
    }

    return 0;
}