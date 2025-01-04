#include <bits/stdc++.h>

using namespace std;

void solve() {
    int count[26];
    fill(count, count + 26, 0);
    for (int i = 1; i <= 4; i++) {
        string s;
        getline(cin, s);
        // cout << s << '\n';
        for (const auto &c : s) {
            if (c >= 'A' && c <= 'Z') count[c - 'A']++;
        }
    }
    int max_count = *max_element(count, count + 26);
    vector<vector<bool>> ans(max_count, vector<bool>(26, false));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            ans[j][i] = true;
        }
    }
    for (int j = max_count; j >= 1; j--) {
        for (int i = 0; i < 26; i++) {
            if (ans[j - 1][i]) {
                cout << "*";
            } else {
                cout << " ";
            }
            if (i != 25) {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (char c = 'A'; c <= 'Z'; c++) cout << c << ' ';
}
int main() {
    solve();
    return 0;
}
