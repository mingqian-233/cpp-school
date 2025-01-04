#include <bits/stdc++.h>
/*
 在图中的九个点上,空出中间的点,其余的点上任意填入数字1到8;1的位置固定不动,然后移动其余的数字,使1到8顺时针从小到大排列.移动的规律是:只能将数字沿线移向空白的点。请编程显示数字移动过程。
 */
using namespace std;

auto transfrom(const auto &a, int mid_place) {
    vector<vector<int>> b(3, vector<int>(3));
    b[0][0] = a[0];
    b[0][1] = a[1];
    b[0][2] = a[2];
    b[1][2] = a[3];
    b[2][2] = a[4];
    b[2][1] = a[5];
    b[2][0] = a[6];
    b[1][0] = a[7];
    b[1][1] = mid_place;
    return b;
}
void print(const auto &v) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[i][j] == 0)
                cout << "0";
            else
                cout << v[i][j];
            if (j != 2) {
                cout << "-";
            }
        }
        cout << '\n';
        if (i == 0)
            cout << "|\\|/|" << '\n';
        if (i == 1)
            cout << "|/|\\|" << '\n';
    }
    cout << '\n';
    // system("pause");
}
void change(auto &a, int t, int ind) {
    // 第一个参数为一维序列，第二个为要被交换到中间的数字
    int swap_ind = 0;  // 在a中索引要被交换的数字的位置
    for (int i = 0; i < 8; i++) {
        if (a[i] == t) {
            swap_ind = i;
            break;
        }
    }
    a[swap_ind] = 0;  // 先把这个位置挖空
    print(transfrom(a, t));
    for (int i = swap_ind - 1;; i--) {
        if (i == -1) i = 7;
        swap(a[(i + 1) % 8], a[i]);
        print(transfrom(a, t));
        if (i == ind) break;
    }
    a[ind] = t;
    print(transfrom(a, 0));
}

int generate(auto &a) {  // 返回顺时针的情况下，左上角为第一个位置，1在第几个位置
    for (int i = 1; i <= 8; i++) a.push_back(i);
    mt19937 g(random_device{}());
    shuffle(a.begin(), a.end(), g);
    for (int i = 0; i < 8; i++) {
        if (a[i] == 1) return i;
    }
    return -1;
}
void play() {
    vector<int> a;
    int place_of_1 = generate(a);
    cout << "The initial state:\n";
    print(transfrom(a, 0));
    for (int move_num = 2; move_num <= 8; move_num++) {
        int ind = (place_of_1 + move_num - 1) % 8;  // 当前枚举到的数字原本应该处于的下标
        if (a[ind] != move_num) change(a, move_num, ind);
    }
    cout << "Done!";
}

int main() {
    play();
    return 0;
}
