#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, s0, s1, e0, e1;
    cin >> n >> s0 >> s1 >> e0 >> e1;

    string s;
    cin >> s;

    ll x = s0, y = s1;

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'E' && e0 > x) x++;
        else if (s[i] == 'W'&& e0 < x) x--;
        else if (s[i] == 'N' && e1 > y) y++;
        else if (s[i] == 'S' && e1 < y) y--;

        if (x == e0 && y == e1) {
            cout << i + 1 << endl;
            return 0;
        }
       
    }

    cout << -1 << endl;
}

// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//     int t, sx, sy, ex, ey;
//     cin >> t >> sx >> sy >> ex >> ey;
 
//     string wind;
//     cin >> wind;
 
//     for (int i = 0; i < t; ++i) {
//         if (sx < ex && wind[i] == 'E') sx++;
//         else if (sx > ex && wind[i] == 'W') sx--;
//         else if (sy < ey && wind[i] == 'N') sy++;
//         else if (sy > ey && wind[i] == 'S') sy--;
 
//         if (sx == ex && sy == ey) {
//             cout << i + 1 << endl;
//             return 0;
//         }
//     }
 
//     cout << -1 << endl;
//     return 0;
// }

