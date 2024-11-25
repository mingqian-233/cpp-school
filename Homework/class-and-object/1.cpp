#include <bits/stdc++.h>
using namespace std;

// use mt19937 to generate random number
int get_rand_num(int lower, int upper) {
    mt19937 rd(random_device{}());
    uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}

class Spirit {
private:
    string name;
    int x;
    int y;
    int health = 1000;
    bool aliveState = true;

public:
    static int number;
    static int alivenumber;

    Spirit() {
        number++;
        alivenumber++;
    }
    Spirit(string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
        number++;
        alivenumber++;
    }

    int takeDamage(int damage) {
        if (aliveState) {
            cout << "Spirit " << name << " has been attacked and lost " << damage << " health." << '\n';
            health -= damage;
            if (health <= 0) {
                health = 0;
                aliveState = false;
                alivenumber--;
                cout << "Spirit is dead." << '\n';
                return 0;  // Dead
            }
            return 1;
        } else {
            cout << "Spirit has been dead. You can't attack a dead Spirit." << '\n';
            return -1;  // Error
        }
    }

    void setPosition(int x, int y, pair<int, int> range = {0, 200}) {
        auto in_range = [&](auto r, pair<int, int> range) {
            for (auto i : r) {
                if (!(i >= range.first && i <= range.second)) {
                    return false;
                }
            }
            return true;
        };
        if (in_range(vector<int>{x, y}, range)) {
            this->x = x;
            this->y = y;
        } else {
            cout << "Invalid position." << '\n';
        }
    }
    void changeName(string name) {
        this->name = name;
    }

    int getPositionX() {
        return x;
    }
    int getPositionY() {
        return y;
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getAliveNumber() {
        return alivenumber;
    }
    void getInfo() {
        cout << "Name: " << name << '\n';
        cout << "Health: " << health << '\n';
        cout << "Position: (" << x << ", " << y << ")" << '\n';
        cout << "Alive: " << (aliveState ? "Yes" : "No") << '\n';
        cout << '\n';
    }
};

int Spirit::number = 0;
int Spirit::alivenumber = 0;

void Print_Rules(bool only_skill = false) {
    if (!only_skill) {
        cout << "The rule is as follows:\n";
        cout << "1. You can move your spirit or use a skill in a round.\n";
        cout << "2. You can use your skill to attack the spirits on the map.\n";
        cout << "3. The spirits on the map will use their skill randomly.\n";
        cout << "4. The spirits will use their skill in the order of their id. If the previous spirit kills the after spirit, the after spirit will not use its skill.\n";
        cout << "5. The game will end when you or all the other spirits on the map are dead.\n";
        cout << "6. If you are dead, you lose the game.\n";
        cout << '\n';
    }
    cout << "The skill of the spirits is as follows:\n";
    cout << "1. Sweep Away(20%): The spirit will attack all the OTHER spirits with a random damage between 0 and 200.\n";
    cout << "2. Odinary Attack(30%): The spirit will attack the player with a random range between 0 and 10 and a random damage between 0 and 100.\n";
    cout << "3. New Born(10%): The spirit will create a new spirit on the map.\n";
    cout << "4. Move(30%): The spirit will move to a random place.\n";
    cout << "5. Heal(10%): The spirit will heal itself with a random health between 0 and 1000.\n";
    cout << "6. Cross Slash(10%): The spirit will all the OTHER spirits in the same line and column with a random damage between 0 and 1000.\n";
    cout << "\n";
    cout << "The skill of the player is as follows:\n";
    cout << "1. Sweep Away: The player will attack all the OTHER spirits with a random damage between 0 and 200.\n";
    cout << "2. The Death is Coming: Kill a random alive spirit in the map.\n";
    cout << "3. Heal: The player will heal itself with a random health between 0 and 1000.\n";
    cout << "4. Cross Slash: The player will attack all the OTHER spirits in the same line and column with 500 damage.\n";
    cout << "5. Move: The player will move to a selected place.\n";
    system("pause");
    system("clr");
}

void test_mode() {
    // task 1
    string name1;
    cout << "Please enter the name of the first spirit: \n";
    cin >> name1;
    cout << "Please enter the position of the first spirit, separated by a space: \n";
    int x1, y1;
    cin >> x1 >> y1;
    Spirit s1(name1, x1, y1);
    s1.getInfo();

    Spirit s2 = Spirit();
    string name2;
    cout << "Please enter the name of the second spirit: \n";
    cin >> name2;
    cout << "Please enter the position of the second spirit, separated by a space: \n";
    int x2, y2;
    cin >> x2 >> y2;
    s2.changeName(name2);
    s2.setPosition(x2, y2);
    s2.getInfo();

    system("pause");
    system("cls");

    // task 2
    cout << "Assume that s1 is attacked by 999 damage and 1 damage." << '\n';
    s1.takeDamage(999);
    s1.getInfo();
    s1.takeDamage(1);
    s1.getInfo();
    system("pause");
    system("cls");

    // task 3
    cout << "Test all the functions." << '\n';
    cout << "Position of s1: (" << s1.getPositionX() << ", " << s1.getPositionY() << ")" << '\n';
    cout << "Name of s1: " << s1.getName() << '\n';
    cout << "Health of s1: " << s1.getHealth() << '\n';
    cout << "Alive number: " << s1.getAliveNumber() << '\n';
    cout << '\n';
    system("pause");
    system("cls");

    // task 4
    cout << "Randomly generate 10 spirits." << '\n';
    Spirit spirits[10];
    for (int i = 0; i < 10; i++) {
        int x = get_rand_num(0, 200);
        int y = get_rand_num(0, 200);
        string name = "Spirit" + to_string(i);
        spirits[i] = Spirit(name, x, y);
        spirits[i].getInfo();
    }
    system("pause");
    system("cls");

    // task 5
    cout << "Randomly attack 10 spirits and attack them." << '\n';
    for (int i = 0; i < 10; i++) {
        int object = get_rand_num(0, 9);
        int damage = get_rand_num(0, 1000);
        spirits[object].takeDamage(damage);
    }
    s1.getInfo();
    s2.getInfo();
    for (int i = 0; i < 10; i++)
        spirits[i].getInfo();

    cout << "Task finished." << '\n';

    system("pause");
    system("cls");

    cout << Spirit::number << ' ' << Spirit::alivenumber << '\n';  // 22 20
    Spirit::number = 0;
    Spirit::alivenumber = 0;
    cout << Spirit::number << ' ' << Spirit::alivenumber << '\n';  // 0 0

    system("pause");
    system("cls");
}
void extra_mode() {
    int map_max_index;
    cout << "Please enter the size of the map(5-20): ";
    while (cin >> map_max_index) {
        if (map_max_index < 5 || map_max_index > 20)
            cout << "Invalid input.\n";
        else
            break;
    }
    vector<vector<int>> mp(map_max_index + 1, vector<int>(map_max_index + 1, 0));
    map<int, bool> alive;  // the id of the spirit, its alive state
    // 0: nothing n: the id of the spirit -1: player
    for (int i = 0; i <= map_max_index; i++) {
        for (int j = 0; j <= map_max_index; j++) {
            mp[i][j] = 0;
        }
    }

    cout << "Please enter the name of your spirit: \n";
    string name;
    cin >> name;

    cout << "Please enter the number of your opponents (1-10): \n";
    int n;
    cin >> n;
    while (n < 1 || n > 10) {
        cout << "Invalid input.\n";
        cin >> n;
    }
    system("clr");
    cout << "Randomly generate " << n << " spirits." << '\n';
    vector<Spirit> spirits;
    for (int i = 0; i < n; i++) {
        int x = get_rand_num(0, map_max_index);
        int y = get_rand_num(0, map_max_index);
        if (mp[x][y] > 0) {
            i--;
            continue;
        }
        mp[x][y] = i;
        string name = "Spirit" + to_string(i);
        spirits.push_back(Spirit(name, x, y));
        spirits[i].getInfo();
    }
    system("pause");
    system("clr");
    cout << "The map is as follows:" << '\n';
    for (int i = 0; i <= map_max_index; i++) {
        for (int j = 0; j <= map_max_index; j++) {
            if (mp[i][j] == 0) cout << '#';
            if (mp[i][j] > 0) cout << '*';
        }
    }
    cout << '\n';
    cout << "Please decide the position of your spirit, separated by a space: \n";
    cout << "Remember, you can't place your spirit on the same position as the other spirits.\n";
    int x, y;
    cin >> x >> y;
    mp[x][y] = -1;
    Spirit player(name, x, y);
    system("clr");
    cout << "The map is as follows:" << '\n';
    for (int i = 0; i <= map_max_index; i++) {
        for (int j = 0; j <= map_max_index; j++) {
            if (mp[i][j] == 0) cout << '#';
            if (mp[i][j] > 0) cout << '*';
            if (mp[i][j] == -1) cout << 'P';
        }
    }
    cout << '\n';
    cout << "Your spirit has been placed on the map." << '\n';
    system("pause");
    system("clr");
    Print_Rules();
    cout << "The game is about to start." << '\n';
    for (int round = 0; Spirit::alivenumber > 1; round++) {
        cout << "Round " << round << '\n';
        cout << "Your spirit: " << '\n';
        player.getInfo();
        cout << "The spirits: " << '\n';
        for (int i = 0; i < n; i++) {
            spirits[i].getInfo();
        }
        cout << "The map:" << '\n';
        for (int i = 0; i <= map_max_index; i++) {
            for (int j = 0; j <= map_max_index; j++) {
                if (mp[i][j] == 0) cout << '#';
                if (mp[i][j] > 0) cout << '*';
                if (mp[i][j] == -1) cout << 'P';
            }
        }
        cout << '\n';
        system("pause");

        cout << "Please choose your action: \n";
        cout << "Skill 1: Sweep Away\n";
        cout << "Skill 2: The Death is Coming\n";
        cout << "Skill 3: Heal\n";
        cout << "Skill 4: Cross Slash\n";
        cout << "Skill 5: Move\n";
        cout << "If you forget the rules, please enter 6.\n";
        int skill;
        cin >> skill;
        if (skill < 1 || skill > 6) {
            cout << "Invalid input.\n";
            round--;
            continue;
        }
        if (skill == 6) {
            Print_Rules(1);
            round--;
            continue;
        }
        if (skill == 1) {
            cout << "You use Sweep Away." << '\n';
            for (int i = 0; i < n; i++) {
                if (mp[spirits[i].getPositionX()][spirits[i].getPositionY()] == i) {
                    int damage = get_rand_num(0, map_max_index);
                    int alive = spirits[i].takeDamage(damage);
                    if (alive == 0)
                        mp[spirits[i].getPositionX()][spirits[i].getPositionY()] = 0;
                }
            }
        }
        if (skill == 2) {
            cout << "You use The Death is Coming." << '\n';
            int object = get_rand_num(0, n - 1);
            if (mp[spirits[object].getPositionX()][spirits[object].getPositionY()] == object) {
                spirits[object].takeDamage(INT_MAX);
            }
        }
        if (skill == 3) {
            cout << "You use Heal." << '\n';
            int heal = get_rand_num(0, 1000);
            player.takeDamage(-heal);
        }
        if (skill == 4) {
            cout << "You use Cross Slash." << '\n';
            for (int i = 0; i < n; i++) {
                if (mp[spirits[i].getPositionX()][spirits[i].getPositionY()] == i) {
                    spirits[i].takeDamage(500);
                }
            }
        }
        if (skill == 5) {
            cout << "You use Move." << '\n';
            int x, y;
            cin >> x >> y;
            auto in_range = [&](auto r, pair<int, int> range) {
                for (auto i : r)
                    if (!(i >= range.first && i <= range.second)) return false;
                return true;
            };
            if (in_range(vector<int>{x, y}, {0, map_max_index}) && mp[x][y] == 0) {
                mp[player.getPositionX()][player.getPositionY()] = 0;
                player.setPosition(x, y);
                mp[x][y] = -1;
            } else {
                cout << "Invalid position." << '\n';
                round--;
                continue;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!alive[i]) continue;
            int skill = get_rand_num(1, 6);
            if (skill == 1) {
                cout << "Spirit " << spirits[i].getName() << " uses Sweep Away." << '\n';
                for (int j = 0; j < n; j++) {
                    if (j != i && mp[spirits[j].getPositionX()][spirits[j].getPositionY()] == j) {
                        int damage = get_rand_num(0, map_max_index);
                        spirits[j].takeDamage(damage);
                    }
                }
                if (mp[player.getPositionX()][player.getPositionY()] == -1) {
                    int damage = get_rand_num(0, map_max_index);
                    player.takeDamage(damage);
                }
            }
            if (skill == 2) {
                cout << "Spirit " << spirits[i].getName() << " uses Odinary Attack." << '\n';
                if (mp[player.getPositionX()][player.getPositionY()] == -1) {
                    int range = get_rand_num(0, 10);
                    if (abs(player.getPositionX() - spirits[i].getPositionX()) <= range && abs(player.getPositionY() - spirits[i].getPositionY()) <= range) {
                        int damage = get_rand_num(0, 100);
                        player.takeDamage(damage);
                    }
                }
            }
            if (skill == 3) {
                cout << "Spirit " << spirits[i].getName() << " uses New Born." << '\n';
                int x = get_rand_num(0, map_max_index);
                int y = get_rand_num(0, map_max_index);
                if (mp[x][y] == 0) {
                    mp[x][y] = n;
                    string name = "Spirit" + to_string(n);
                    spirits.push_back(Spirit(name, x, y));
                    spirits[n].getInfo();
                    n++;
                }
            }
            if (skill == 4) {
                cout << "Spirit " << spirits[i].getName() << " uses Move." << '\n';
                mp[spirits[i].getPositionX()][spirits[i].getPositionY()] = 0;
            front:
                int x = get_rand_num(0, map_max_index);
                int y = get_rand_num(0, map_max_index);
                if (mp[x][y] == 0) {
                    mp[x][y] = i;
                    spirits[i].setPosition(x, y);
                } else {
                    goto front;
                }
            }
            if (skill == 5) {
                cout << "Spirit " << spirits[i].getName() << " uses Heal." << '\n';
                int heal = get_rand_num(0, 1000);
                spirits[i].takeDamage(-heal);
            }
            if (skill == 6) {
                cout << "Spirit " << spirits[i].getName() << " uses Cross Slash." << '\n';
                int damage = get_rand_num(0, 1000);
                for (int j = 0; j < n; j++) {
                    if (j != i && mp[spirits[j].getPositionX()][spirits[j].getPositionY()] == j) {
                        spirits[j].takeDamage(damage);
                    }
                }
                if (mp[player.getPositionX()][player.getPositionY()] == -1) {
                    player.takeDamage(damage);
                }
            }
        }
        if (player.getHealth() <= 0)
            cout << "You lose\n";
        else
            cout << "You win.\n";
        system("pause");
        system("clr");
    }
}
int main() {
    cout << "Hello! Please choose the mode:\n";
    cout << "1. Test Mode:\n";
    cout << "2. Extra Mode:\n";
    cout << "3. Exit\n";
    int mode;
    cin >> mode;
    if (mode == 1)
        test_mode();
    else if (mode == 2)
        extra_mode();
    else if (mode == 3)
        return 0;
    else {
        cout << "Invalid input.\n";
        system("pause");
        system("clr");
        main();
    }
    return 0;
}