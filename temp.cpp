#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    // 只用cin、cout 可以加速
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 一行带空格的输入字符串
    string line;
    getline(cin, line);
    stringstream ss(line);
    string tmp;
    while (ss >> tmp) {
        cout << tmp << endl;
    }

    // 输出保留两位小数
    int x;
    cout << setiosflags(ios::fixed) << setprecision(2) << (float)x;

    return 0;
}
