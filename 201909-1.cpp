#include <bits/stdc++.h>

using namespace std;

int N, M;
int T = 0, k = 0, P = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int a, b = 0, c;
        cin >> a;
        T += a;
        for (int j = 1; j <= M; ++j) {
            cin >> c;
            b += c;
        }
        T += b;
        if (abs(b) > P) {
            k = i;
            P = abs(b);
        }
    }
    cout << T << " " << k << " " << P;
    return 0;
}
