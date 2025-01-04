#include <bits/stdc++.h>
using namespace std;

int get_rand_num(int lower, int upper) {
    mt19937 rd(random_device{}());
    uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}

void output(string guess, string answer) {
    // 这里采用wordle的视觉效果，如果位置对了就用绿色底色的数字，如果位置不对但是数字对了就用黄色底色的数字，如果数字不对就用红色底色的数字
    for (int i = 0; i < 4; i++) {
        if (guess[i] == answer[i]) {
            cout << "\033[42;30m" << guess[i] << "\033[0m";
        } else if (answer.find(guess[i]) != string::npos) {
            cout << "\033[43;30m" << guess[i] << "\033[0m";
        } else {
            cout << "\033[41;30m" << guess[i] << "\033[0m";
        }
    }
    cout << endl;
}
void game() {
    int answer = get_rand_num(1000, 9999);
    cout << "Rule:\n";
    cout << "Please guess a 4-digit number!" << endl;
    cout << "If the position is right, output the digit with the \033[42;30mgreen\033[0m background;\n";
    cout << "If the position is wrong, but the number is right, use the number with the \033[43;30myellow\033[0m background;\n";
    cout << "If the number is wrong, use the number with the \033[41;30mred\033[0m background.\n";
    cout << "Let's start!\n\n";
    int guess;
    while (guess != answer) {
        cin >> guess;
        if (guess < 1000 || guess > 9999) {
            cout << "Invalid input. Please enter a 4-digit number." << endl;
            continue;
        }
        output(to_string(guess), to_string(answer));
    }
    cout << "You win! ^_^" << endl;
}
int main() {
    game();
    bool new_game;
    cout << "New game? (1/0): ";
    cin >> new_game;
    if (new_game) {
        system("clear");
        main();
    } else {
        cout << "Goodbye!" << endl;
        return 0;
    }
    return 0;
}