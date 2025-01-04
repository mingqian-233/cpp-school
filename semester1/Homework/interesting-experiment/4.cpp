#include <bits/stdc++.h>

using namespace std;
struct Node {
    vector<int> state;  // 棋盘状态
    int step;  // 步数
    queue<vector<int>> s;  // 存储路径
    Node(vector<int> state, int step, queue<vector<int>> s) : state(state), step(step), s(s) {}
};
void solve() {
    vector<int> a = {1, 1, 1, 0, 2, 2, 2};
    map<vector<int>, bool> m;
    m[a] = true;
    queue<Node> q;
    queue<vector<int>> init;
    init.push(a);
    q.push(Node(a, 0, init));
    while (!q.empty()) {
        auto [state, step, s] = q.front();
        q.pop();
        auto pos = find(state.begin(), state.end(), 0) - state.begin();
        // cout << pos;
        if (state == vector<int>{2, 2, 2, 0, 1, 1, 1}) {
            cout << "The min step is:" << step << endl;
            while (!s.empty()) {
                auto state = s.front();
                s.pop();
                for (const auto &i : state) cout << i << " ";
                cout << '\n';
            }
            return;
        }
        for (int i = -2; i <= 2; i++) {
            if (pos + i < 0 || pos + i >= 7 || i == 0) continue;
            swap(state[pos], state[pos + i]);
            if (!m[state]) {
                m[state] = true;
                s.push(state);
                q.push({state, step + 1, s});
            }
            swap(state[pos], state[pos + i]);
        }
    }
}
int main() {
    solve();
    return 0;
}
