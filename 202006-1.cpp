#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n = 0, m = 0;
    cin >> n >> m;
    vector<vector<array<ll, 2>>> points(2);
    ll xi, yi;
    char typei;
    ll ai, bi, ci;

    while (n--) {
        cin >> xi >> yi >> typei;
        points[typei - 'A'].push_back({xi, yi});
    }
    while (m--) {
        cin >> ai >> bi >> ci;
        for (auto &p : points) {
            for (ll i = 1; i < p.size(); ++i) {
                if ((ai + bi * p[i][0] + ci * p[i][1] > 0) ^
                    (ai + bi * p[0][0] + ci * p[0][1] > 0)) {
                    cout << "No\n";
                    goto loop;
                }
            }
        }
        if ((ai + bi * points[0][0][0] + ci * points[0][0][1] > 0) ^
            (ai + bi * points[1][0][0] + ci * points[1][0][1] > 0))
            cout << "Yes\n";
        else
            cout << "No\n";
    loop:;
    }
    return 0;
}