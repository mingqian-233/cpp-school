#include <bits/stdc++.h>

using namespace std;

const char type[] = {'S', 'H', 'D', 'C'};
const string number[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

vector<string> get_card_sequence() {
    vector<string> card_sequence;
    for (const auto &t : type) {
        for (const auto &n : number) {
            string card;
            card += t;
            card += n;
            card_sequence.push_back(card);
        }
    }

    mt19937 rd(random_device{}());
    shuffle(card_sequence.begin(), card_sequence.end(), rd);

    return card_sequence;
}

void deal_cards() {
    vector<string> card_sequence = get_card_sequence();
    for (int i = 0; i < 4; i++) {
        cout << "Player " << i + 1 << ": ";
        for (int j = 0; j < 13; j++) {
            cout << card_sequence[i * 13 + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    deal_cards();
    return 0;
}
