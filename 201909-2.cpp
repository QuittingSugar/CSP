#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
bool drop[MAXN];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int N = 0, m = 0;
    int T = 0, D = 0, E = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        drop[i] = false;
        int a, b;
        cin >> m >> a;
        while (--m) {
            cin >> b;
            if (b <= 0) {
                a += b;
            } else {
                if (a > b) {
                    if (!drop[i])
                        ++D;
                    drop[i] = true;
                }
                a = b;
            }
        }
        T += a;
    }
    for (int i = 0; i < N; ++i) {
        if (drop[i] && drop[(i + 1) % N] && drop[(i + 2) % N])
            ++E;
    }
    cout << T << " " << D << " " << E;
    return 0;
}