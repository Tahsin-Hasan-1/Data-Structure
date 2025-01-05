#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    string val;
    node* next;
    node* prev;
    node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insrt_tail(node*& head, string val, node*& tail) {
    node* t = new node(val);
    if (head == NULL) {
        head = t;
        tail = t;
        return;
    }
    tail->next = t;
    t->prev = tail;
    tail = t;
}

void browser_hist(node* head, int q) {
    node* t = head;

    while (q--) {
        string f, j;
        cin >> f;

        if (f == "visit") {
            cin >> j;
            node* i = head;
            bool g = false;

            while (i != NULL) {
                if (i->val == j) {
                    t = i;
                    cout << t->val << endl;
                    g = true;
                    break;
                }
                i = i->next;
            }

            if (!g) {
                cout << "Not Available" << endl;
            }
        } else if (f == "prev") {
            if (t->prev != NULL) {
                t = t->prev;
                cout << t->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (f == "next") {
            if (t->next != NULL) {
                t = t->next;
                cout << t->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }  // tahsin hasan
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    string val;
    int q;

    while (true) {
        cin >> val;
        if (val == "end") {
            break;
        }
        insrt_tail(head, val, tail);
    }

    cin >> q;

    browser_hist(head, q);

    return 0;
}
