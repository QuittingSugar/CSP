#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int n;
string formula;
unordered_map<string, int> ans;

// ����formula��[first,last]�����Ӧ���֣�ע�⺯������֮�󴫵ݸ�first��ʵ�ν��ƶ�����һ���������ַ���λ��
int computeDigit(int &first, int last) {
    int i = 0;
    for (; first <= last && isdigit(formula[first]); ++first)
        i = i * 10 + formula[first] - '0';
    return i == 0 ? 1 : i;
}

// ����formula��[first,last]�����ԭ���Լ����Ӧϵ��������ϵ��Ϊe
void f(int first, int last, int e) {
    // ��ѧʽ�ǵ���ԭ��
    if (first == last || (last - first == 1 && islower(formula[last]))) {
        ans[formula.substr(first, last - first + 1)] += e;
        return;
    }
    // �û�ѧʽ������ԭ�ӻ���ϵ��Ҫ���ϸû�ѧʽ��ʼϵ��
    e *= computeDigit(first, last);
    // ������ѧʽ
    for (int i = first, j = i + 1; i <= last; i = j, ++j) {
        // ��ԭ��
        if (isupper(formula[i])) {
            if (j <= last && islower(formula[j]))
                ++j;
            int k = j;
            f(i, k - 1, e * computeDigit(j, last)); // �ݹ鴦��
        } else if (formula[i] == '(') {             // ������
            for (int num = 1; num != 0; ++j) {
                if (formula[j] == '(')
                    ++num;
                else if (formula[j] == ')')
                    --num;
            }
            int k = j;
            f(i + 1, k - 1, e * computeDigit(j, last)); // �ݹ鴦��
        }
    }
}

// ��+���뻯ѧʽ
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
        // ������ʽ��=�ָ��������
        int k = formula.find('=');
        expression(0, k - 1, 1);
        expression(k + 1, formula.size() - 1, -1);
        // ������û��ԭ�Ӷ�Ӧ������Ϊ0
        auto i =
            find_if(ans.begin(), ans.end(),
                    [](const pair<string, int> &p) { return p.second != 0; });
        cout << ((i == ans.end()) ? "Y" : "N") << "\n";
    }
    return 0;
}
