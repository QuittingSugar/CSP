#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 500005;
pair<ll, ll> u[MAXN], v[MAXN];

// 申请大数组时可以放在全局静态区，放置局部爆栈
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll res = 0;
    int n = 0, a = 0, b = 0;
    cin >> n >> a >> b;

    for (int i = 0; i < a; ++i) {
        cin >> u[i].first >> u[i].second;
    }
    for (int j = 0; j < b; ++j) {
        cin >> v[j].first >> v[j].second;
    }

    for (int i = 0, j = 0; i < a && j < b;) {
        if (u[i].first < v[j].first)
            ++i;
        else if (u[i].first > v[j].first)
            ++j;
        else if (u[i].first == v[j].first) {
            res += (u[i++].second * v[j++].second);
        }
    }
    cout << res;
    return 0;
}

// 解法2
int main1() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll res = 0;
    ll n = 0, a = 0, b = 0;
    ll x = 0, y = 0;
    cin >> n >> a >> b;
    unordered_map<ll, ll> mp;
    while (a--) {
        cin >> x >> y;
        mp[x] = y;
    }
    while (b--) {
        cin >> x >> y;
        res += mp[x] * y;
    }
    cout << res;
    return 0;
}
