#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const ull U0 = 314882150829468584;
const ull U1 = 427197303358170108;
const ull U2 = 1022292690726729920;
const ull U3 = 1698479428772363217;
const ull U4 = 2006101093849356424;

const ull mo = 2009731336725594113;

ull f(ull x) {
    ull res = (x mod mo)mod 2019;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}