#include <iostream>
using namespace std;

struct node {
    int val;
    node* nxt;
    node(int x) : val(x), nxt(NULL) {}
    node(int x, node* nxt) : val(x), nxt(nxt) {}
    node* create_list_by_head_insert() {
        node* head = NULL;
        int x;
        while (cin >> x) {
            if (x == 0) break;
            node* new_node = new node(x, head);
            head = new_node;
        }
        return head;
    }
    node* create_list_by_tail_insert() {
        node *head = NULL, *tail = NULL;
        int x;
        while (cin >> x) {
            if (x == 0) break;
            node* new_node = new node(x);
            if (head == NULL) {
                head = tail = new_node;
            } else {
                tail->nxt = new_node;
                tail = new_node;
            }
        }
        return head;
    }
    void output_list(node* head) {
        node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->val << " ";
            tmp = tmp->nxt;
        }
        cout << endl;
    }
    void insert_after_ith_number(node*& head, int i, int x) {
        node* tmp = head;
        if (i == 0) {
            node* new_node = new node(x, head);
            head = new_node;
            return;
        }
        while (i > 1) {
            tmp = tmp->nxt;
            i--;
            if (tmp == NULL) {
                cout << "i is too large" << endl;
                return;
            }
        }
        node* new_node = new node(x, tmp->nxt);
        tmp->nxt = new_node;
    }
    void erase_ith_number(node*& head, int i) {
        node* tmp = head;
        if (i == 1) {
            head = head->nxt;
            delete tmp;
            return;
        }
        while (i > 2) {
            tmp = tmp->nxt;
            i--;
            if (tmp == NULL) {
                cout << "i is too large" << endl;
                return;
            }
        }
        node* del_node = tmp->nxt;
        tmp->nxt = del_node->nxt;
        delete del_node;
    }
    void find_ith_number(node* head, int i) {
        node* tmp = head;
        for (int j = 1; j < i; j++) {
            tmp = tmp->nxt;
            if (tmp == NULL) {
                cout << "The " << i << "th number is not exist." << endl;
                return;
            }
        }
        cout << "The " << i << "th number is " << tmp->val << endl;
    }
    void insertion_sort(node* head) {
        for (node* i = head->nxt; i != NULL; i = i->nxt) {
            node* t = head;
            while (t != i) {
                if (t->val > i->val) swap(t->val, i->val);
                t = t->nxt;
            }
        }
    }
    // 采用断链和连接的方式进行插入排序：
    void insertion_sort_by_node(node*& head) {
        node* i;
        int cnt = 0;
        for (i = head; i != NULL; i = i->nxt) {
            cnt++;
            int insert_after_ith;
            node* tmp = head;
            for (insert_after_ith = 0; i->val > tmp->val; insert_after_ith++) {
                tmp = tmp->nxt;
            }
            cout << "insert_after_ith: " << insert_after_ith << endl;
            int val = i->val;
            erase_ith_number(head, cnt);
            insert_after_ith_number(head, insert_after_ith, val);
            output_list(head);
        }
    }
};
int main() {
    node* l1 = NULL;
    l1 = l1->create_list_by_head_insert();
    node* l2 = NULL;
    l2 = l2->create_list_by_tail_insert();
    cout << "l1: ";
    l1->output_list(l1);
    cout << "l2: ";
    l2->output_list(l2);

    // l1->insert_after_ith_number(l1, 2, 100);
    // cout << "l1: ";
    // l1->output_list(l1);

    l1->erase_ith_number(l1, 1);
    cout << "l1: ";
    l1->output_list(l1);

    // l1->find_ith_number(l1, 2);
    // l1->find_ith_number(l1, 10);

    l1->insertion_sort_by_node(l1);
    cout << "l1 after sort: ";
    l1->output_list(l1);

    return 0;
}