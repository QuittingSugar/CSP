#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    // 值（对应上下左右的垃圾数，四个对角的垃圾数）
    map<array<int, 2>, array<int, 2>> mp;
    array<int, 2> p;
    for (int i = 0; i < n; ++i) {
        cin >> p[0] >> p[1];
        mp.insert({p, {0, 0}});
        for (auto &i : mp) {
            auto &p2 = i.first;
            if ((abs(p[0] - p2[0]) == 1 && p[1] == p2[1]) ||
                (p[0] == p2[0] && abs(p[1] - p2[1]) == 1)) {
                ++mp[p][0];
                ++mp[p2][0];
            } else if (abs(p[0] - p2[0]) == 1 && abs(p[1] - p2[1]) == 1) {
                ++mp[p][1];
                ++mp[p2][1];
            }
        }
    }
    array<int, 5> ans{};
    for (auto &i : mp) {
        if (i.second[0] == 4)
            ++ans[i.second[1]];
    }
    for (int i : ans)
        cout << i << "\n";
    return 0;
}
