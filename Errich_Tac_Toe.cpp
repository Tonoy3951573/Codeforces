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
    cin>>n;
    string mat[n];
    string mat1[n];
    string mat2[n];
    string mat3[n];
    string str;

    int x = 0,x1 = 0,x2 = 0,x3 = 0;
    for(int i = 0; i < n; i++){
        
        cin>>str;
        mat[i] = str;
        mat1[i] = str;
        mat2[i] = str;
        mat3[i] = str;
    }
    for(int i = 0; i < n; i++){
        for(int j  = 0; j < n; j++){
            if(mat[i][j] == '.') continue;
            else if((i+j)%3 == 0){
                mat1[i][j] = 'O';
                mat2[i][j] = 'X';
                mat3[i][j] = 'X';
                x++;
                x1++;
            }
            else if((i+j)%3 == 1){
                mat1[i][j] = 'X';
                mat2[i][j] = 'O';
                mat3[i][j] = 'X';
                x++;
                x2++;
            }
            else if((i+j)%3 == 2){
                mat1[i][j] = 'X';
                mat2[i][j] = 'X';
                mat3[i][j] = 'O';
                x++;
                x3++;
            }
        }
    }
    if(x1 <= x/3){
        for(int i = 0; i < n; i++){
            cout<<mat1[i]<<endl;
        }
    }
    else if(x2 <= x/3){
        for(int i = 0; i < n; i++){
            cout<<mat2[i]<<endl;
        }
    }
    else if(x3 <= x/3){
        for(int i = 0; i < n; i++){
            cout<<mat3[i]<<endl;
        }
    }
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