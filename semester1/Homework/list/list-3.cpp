#include <iostream>
using namespace std;

int n;
struct node {
    int val;
    node *prev, *nxt;
    node(int x) : val(x), prev(NULL), nxt(NULL) {}
    node(int x, node* prev, node* nxt) : val(x), prev(prev), nxt(nxt) {}
    node* create_list() {
        cin >> n;
        node *head = NULL, *tail = NULL;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (head == NULL) {
                head = new node(x);
                tail = head;
            } else {
                tail->nxt = new node(x, tail, NULL);
                tail = tail->nxt;
            }
        }
        tail->nxt = head;
        head->prev = tail;
        return head;
    }
    void insert(node*& head, node*& tail, int i, bool front, int val) {  // front==1:insert to the front of ith element
        if (front) {
            if (i == 1) {
                node* new_node = new node(val, tail, head);
                head->prev = new_node;
                head = new_node;
            } else {
                node* cur = head;
                for (int j = 1; j < i; j++) cur = cur->nxt;
                node* new_node = new node(val, cur->prev, cur);
                cur->prev->nxt = new_node;
                cur->prev = new_node;
            }
        } else {
            if (i == n) {
                node* new_node = new node(val, tail, head);
                tail->nxt = new_node;
                tail = new_node;
            } else {
                node* cur = head;
                for (int j = 1; j < i; j++) cur = cur->nxt;
                node* new_node = new node(val, cur, cur->nxt);
                cur->nxt->prev = new_node;
                cur->nxt = new_node;
            }
        }
        n++;
    }
    void erase_ith_element(node*& head, node*& tail, int i) {
        if (i == 1) {
            head = head->nxt;
            head->prev = tail;
            tail->nxt = head;
        } else {
            node* cur = head;
            for (int j = 1; j < i; j++) cur = cur->nxt;
            cur->prev->nxt = cur->nxt;
            cur->nxt->prev = cur->prev;
        }
        n--;
    }
    void find_x(node* head, int x) {
        bool flag = 0;
        node* cur = head;
        for (int i = 0; i < n; i++) {
            if (cur->val == x) {
                cout << i + 1 << " ";
                flag = 1;
            }
            cur = cur->nxt;
        }
        if (!flag) cout << "No this element!";
        cout << endl;
    }
    void output_list(const node* head) {
        const node* cur = head;
        for (int i = 0; i < n; i++) {
            cout << cur->val << " ";
            cur = cur->nxt;
        }
        cout << endl;
    }
};
int main() {
    node* l1 = NULL;
    l1 = l1->create_list();
    l1->output_list(l1);

    int i, x;
    string s;
    cout << "Please input the position, value and the \"front\" or \"back\"  of the element you want to insert:" << endl;
    cin >> i >> x >> s;
    l1->insert(l1, l1->prev, i, s == "front", x);
    l1->output_list(l1);
    cout << "Please input the position, value and the \"front\" or \"back\"  of the element you want to insert:" << endl;
    cin >> i >> x >> s;
    l1->insert(l1, l1->prev, i, s == "front", x);
    l1->output_list(l1);

    cout << "Please input the position of the element you want to erase:" << endl;
    cin >> i;
    l1->erase_ith_element(l1, l1->prev, i);
    l1->output_list(l1);

    cout << "Please input the element you want to find:" << endl;
    cin >> x;
    l1->find_x(l1, x);

    return 0;
}