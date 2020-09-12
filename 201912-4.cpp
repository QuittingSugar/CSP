#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(505);    // 存储节点的边关系
vector<vector<int>> ans(505, {0}); // 存储每个节点的主链
int n, m, t, k;
map<int, unordered_map<int, array<vector<int>, 2>>>
    actions; // 存储接受链和产生块操作

// 其他节点传递过来的新链New能否被接受
bool canAccept(const vector<int> &Old, const vector<int> &New) {
    return Old.size() != New.size() ? Old.size() < New.size()
                                    : Old.back() > New.back();
}

// 将节点v的主链广播出去
void diffuse(int v, int time) {
    for (int i : graph[v]) {
        auto &chain = actions[time][i][0];
        if ((chain.empty() && canAccept(ans[i], ans[v])) ||
            (!chain.empty() && canAccept(chain, ans[v])))
            chain = ans[v];
    }
}

// 查询a节点在b时刻的主链
void query(int a, int b) {
    for (auto &action : actions) { // 遍历所有接受链和产生块的操作
        int curTime = action.first;
        if (curTime > b) // 当前操作时刻 >b，结束循环
            break;
        for (auto &vertex : action.second) {
            int v = vertex.first;            // 获取该操作的节点编号
            auto &chain = vertex.second[0];  // 要接受的链
            auto &blocks = vertex.second[1]; // 要产生的块
            bool canDiffuse = canAccept(ans[v], chain) ||
                              !blocks.empty(); // 节点v是否要向外广播主链
            if (canAccept(ans[v], chain))      // 先接受其他节点的主链
                ans[v] = chain;
            for (int b : blocks) // 再产生块
                ans[v].push_back(b);
            if (canDiffuse) // 向外广播
                diffuse(v, curTime + t);
        }
    }
    // 删除b时刻及其以前的所有操作，避免重复处理
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
