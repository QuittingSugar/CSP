#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool hasSeven(int n) {
    for (; n != 0; n /= 10)
        if (n % 10 == 7)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    array<int, 4> ans{};
    for (int i = 1;; ++i) {
        if (i % 7 == 0 || hasSeven(i))
            ++ans[(i - 1) % 4];
        else
            --n;
    }
    for (int i : ans)
        cout << i << "\n";
    return 0;
}
