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
    // ֻ��cin��cout ���Լ���
    ios::sync_with_stdio(false);
    cin.tie(0);

    // һ�д��ո�������ַ���
    string line;
    getline(cin, line);
    stringstream ss(line);
    string tmp;
    while (ss >> tmp) {
        cout << tmp << endl;
    }

    // ���������λС��
    int x;
    cout << setiosflags(ios::fixed) << setprecision(2) << (float)x;

    return 0;
}
