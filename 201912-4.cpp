#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(505);    // �洢�ڵ�ı߹�ϵ
vector<vector<int>> ans(505, {0}); // �洢ÿ���ڵ������
int n, m, t, k;
map<int, unordered_map<int, array<vector<int>, 2>>>
    actions; // �洢�������Ͳ��������

// �����ڵ㴫�ݹ���������New�ܷ񱻽���
bool canAccept(const vector<int> &Old, const vector<int> &New) {
    return Old.size() != New.size() ? Old.size() < New.size()
                                    : Old.back() > New.back();
}

// ���ڵ�v�������㲥��ȥ
void diffuse(int v, int time) {
    for (int i : graph[v]) {
        auto &chain = actions[time][i][0];
        if ((chain.empty() && canAccept(ans[i], ans[v])) ||
            (!chain.empty() && canAccept(chain, ans[v])))
            chain = ans[v];
    }
}

// ��ѯa�ڵ���bʱ�̵�����
void query(int a, int b) {
    for (auto &action : actions) { // �������н������Ͳ�����Ĳ���
        int curTime = action.first;
        if (curTime > b) // ��ǰ����ʱ�� >b������ѭ��
            break;
        for (auto &vertex : action.second) {
            int v = vertex.first;            // ��ȡ�ò����Ľڵ���
            auto &chain = vertex.second[0];  // Ҫ���ܵ���
            auto &blocks = vertex.second[1]; // Ҫ�����Ŀ�
            bool canDiffuse = canAccept(ans[v], chain) ||
                              !blocks.empty(); // �ڵ�v�Ƿ�Ҫ����㲥����
            if (canAccept(ans[v], chain))      // �Ƚ��������ڵ������
                ans[v] = chain;
            for (int b : blocks) // �ٲ�����
                ans[v].push_back(b);
            if (canDiffuse) // ����㲥
                diffuse(v, curTime + t);
        }
    }
    // ɾ��bʱ�̼�����ǰ�����в����������ظ�����
    actions.erase(actions.begin(), actions.upper_bound(b));
    cout << ans[a].size();
    for (int i : ans[a])
        cout << " " << i;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> t >> k;
    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b;
        if (cin.get() == '\n' || cin.eof()) {
            query(a, b);
        } else {
            cin >> c;
            actions[b][a][1].push_back(c);
        }
    }
    return 0;
}
