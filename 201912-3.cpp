#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int n;
string formula;
unordered_map<string, int> ans;

// 返回formula的[first,last]区间对应数字，注意函数返回之后传递给first的实参将移动到第一个非数字字符的位置
int computeDigit(int &first, int last) {
    int i = 0;
    for (; first <= last && isdigit(formula[first]); ++first)
        i = i * 10 + formula[first] - '0';
    return i == 0 ? 1 : i;
}

// 计算formula的[first,last]区间的原子以及其对应系数，基本系数为e
void f(int first, int last, int e) {
    // 化学式是单个原子
    if (first == last || (last - first == 1 && islower(formula[last]))) {
        ans[formula.substr(first, last - first + 1)] += e;
        return;
    }
    // 该化学式内所有原子基本系数要乘上该化学式起始系数
    e *= computeDigit(first, last);
    // 遍历化学式
    for (int i = first, j = i + 1; i <= last; i = j, ++j) {
        // 是原子
        if (isupper(formula[i])) {
            if (j <= last && islower(formula[j]))
                ++j;
            int k = j;
            f(i, k - 1, e * computeDigit(j, last)); // 递归处理
        } else if (formula[i] == '(') {             // 遇到（
            for (int num = 1; num != 0; ++j) {
                if (formula[j] == '(')
                    ++num;
                else if (formula[j] == ')')
                    --num;
            }
            int k = j;
            f(i + 1, k - 1, e * computeDigit(j, last)); // 递归处理
        }
    }
}

// 按+分离化学式
void expression(int first, int last, int e) {
    for (int i = first, j = first; i <= last; i = j + 1) {
        j = formula.find('+', i);
        if (j == string::npos || j > last)
            j = last + 1;
        f(i, j - 1, e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> formula;
        ans.clear();
        // 将方程式按=分割成两部分
        int k = formula.find('=');
        expression(0, k - 1, 1);
        expression(k + 1, formula.size() - 1, -1);
        // 查找有没有原子对应个数不为0
        auto i =
            find_if(ans.begin(), ans.end(),
                    [](const pair<string, int> &p) { return p.second != 0; });
        cout << ((i == ans.end()) ? "Y" : "N") << "\n";
    }
    return 0;
}
