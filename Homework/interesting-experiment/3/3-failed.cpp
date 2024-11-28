#include <bits/stdc++.h>
/*
 在图中的九个点上,空出中间的点,其余的点上任意填入数字1到8;1的位置固定不动,然后移动其余的数字,使1到8顺时针从小到大排列.移动的规律是:只能将数字沿线移向空白的点。请编程显示数字移动过程。
 */
using namespace std;

const vector<vector<int>> final_result[8] = {
    {{1, 2, 3},
     {8, 0, 4},
     {7, 6, 5}},
    {{8, 1, 2},
     {7, 0, 3},
     {6, 5, 4}},
    {{7, 8, 1},
     {6, 0, 2},
     {5, 4, 3}},
    {{2, 3, 4},
     {1, 0, 5},
     {8, 7, 6}},
    {{6, 7, 8},
     {5, 0, 1},
     {4, 3, 2}},
    {{3, 4, 5},
     {2, 0, 6},
     {1, 8, 7}},
    {{4, 5, 6},
     {3, 0, 7},
     {2, 1, 8}},
    {{5, 6, 7},
     {4, 0, 8},
     {3, 2, 1}},
};

void generate(auto &a, auto &ans) {
    int one_place = 0;
    a[1][1] = 0;
    vector<int> v;
    for (int i = 1; i <= 8; i++) v.push_back(i);
    mt19937 g(random_device{}());
    shuffle(v.begin(), v.end(), g);
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                flag = 1;
                continue;
            }
            a[i][j] = v[i * 3 + j - flag];
            if (a[i][j] == 1) one_place = i * 3 + j - flag;
        }
    }
    ans = final_result[one_place];
}
void output(const auto &a) {
    /*
    按照一个米字格的格式字符画输出
    1-2-3
    |\|/|
    4-0-5
    |/|\|
    6-7-8
     */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0)
                cout << "0";
            else
                cout << a[i][j];
            if (j != 2) {
                cout << "-";
            }
        }
        cout << '\n';
        if (i != 2)
            cout << "|\\|/|" << '\n';
    }
    cout << '\n';
}

#define pii pair<int, int>
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

void bfs(vector<vector<int>> &a, const vector<vector<int>> &ans) {
    map<vector<vector<int>>, bool> mp;
    queue<pair<vector<vector<int>>, pii>> q;
    queue<stack<vector<vector<int>>>> q2;
    q.push({a, {1, 1}});
    mp[a] = 1;

    while (!q.empty()) {
        auto [now, zero] = q.front();
        q.pop();
        auto st = q2.front();
        q2.pop();

        if (now == ans) {
            while (!st.empty()) {
                output(st.top());
                st.pop();
            }
            return;
        }

        auto [zx, zy] = zero;
        for (int i = 0; i < 8; i++) {
            int x = zx + dx[i];
            int y = zy + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                swap(now[x][y], now[zx][zy]);
                if (!mp[now]) {
                    q.push({now, {x, y}});
                    mp[now] = 1;
                    st.push(now);
                    q2.push(st);
                }
                swap(now[x][y], now[zx][zy]);
            }
        }
    }
}

void play() {
    vector<vector<int>> a(3, vector<int>(3, 0)), ans = a;
    // 输出a
    generate(a, ans);
    output(a);
    // output(ans);
    bfs(a, ans);
}

int main() {
    play();
    return 0;
}
