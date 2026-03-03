#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << "\n"
#else
    #define debug(x)
#endif
void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    map<int,int> ffa, ffb;

    int len = 0, i;

    // array a
    for (i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) len++;
        else {
            ffa[a[i]] = max(ffa[a[i]], len + 1);
            len = 0;
        }
    }
    ffa[a[i]] = max(ffa[a[i]], len + 1);

    len = 0;

    // array b
    for (i = 0; i < n - 1; i++) {
        if (b[i] == b[i + 1]) len++;
        else {
            ffb[b[i]] = max(ffb[b[i]], len + 1);
            len = 0;
        }
    }
    ffb[b[i]] = max(ffb[b[i]], len + 1);

    int ans = 0;

    for (auto &[x, v] : ffa)
        ans = max(ans, v + ffb[x]);

    for (auto &[x, v] : ffb)
        ans = max(ans, v + ffa[x]);

    cout << ans << '\n';
}

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifndef ONLINE_JUDGE
    cout.flush();
    ifstream expected("ex_output.txt");
    ifstream actual("output.txt");

    if (!expected.is_open() || !actual.is_open()) {
        cerr << "Error: Could not open ex_output.txt or output.txt\n";
        return 1;
    }

    string expLine, actLine;
    int lineNum = 1;
    bool allPassed = true;
    int mismatches = 0, total = 0;

    auto normalize = [](string &s) {
        if (!s.empty() && s.back() == '\r') s.pop_back();
        while (!s.empty() && isspace(s.back())) s.pop_back();
    };

    auto toLowerStr = [](string &s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    };

    while (true) {
        bool expOk = (bool)getline(expected, expLine);
        bool actOk = (bool)getline(actual, actLine);

        if (!expOk && !actOk) break;

        if (expOk) { normalize(expLine); toLowerStr(expLine); }
        if (actOk) { normalize(actLine); toLowerStr(actLine); }

        if (expOk != actOk || expLine != actLine) {
            cerr << "Mismatch at line " << lineNum << ":\n";
            cerr << "Expected: \"" << expLine << "\"\n";
            cerr << "Got     : \"" << actLine << "\"\n";
            allPassed = false;
            mismatches++;
        }
        lineNum++;
        total++;
    }

    cerr << "\n--- Test Summary ---\n";
    if (allPassed) {
        cerr << "✅ All " << total << " test cases passed!\n";
    } else {
        cerr << "❌ " << mismatches << " mismatches out of " << total << " test cases.\n";
    }
#endif
    return 0;
}