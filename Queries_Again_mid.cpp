#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node* next;
    node* prev;

    node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(node* head) {
    cout << "L -> ";
    node* t = head;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}

void print_reverse(node* tail) {
    cout << "R -> ";
    node* t = tail;
    while (t) {
        cout << t->val << " ";
        t = t->prev;
    }
    cout << endl;
}

void insrt_at_any(node*& head, node*& tail, int ind, int val) {
    if (ind < 0) {
        cout << "Invalid" << endl;
        return;
    }

    node* n = new node(val);

    if (ind == 0) {
        if (head == NULL) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    } else {
        node* t = head;
        int i = 0;

        while (t != NULL && i < ind - 1) {
            t = t->next;
            i++;
        }

        if (t == NULL || (ind > 1 && t->next == NULL && i != ind - 1)) {
            cout << "Invalid" << endl;
            return;
        }

        if (t->next == NULL) {
            t->next = n;
            n->prev = t;
            tail = n;
        } else {
            n->next = t->next;
            n->prev = t;
            t->next->prev = n;
            t->next = n;
        }  // tahsin hasan
    }

    print_forward(head);
    print_reverse(tail);
}

int main() {
    int Q;
    cin >> Q;

    node* head = NULL;
    node* tail = NULL;

    for (int i = 0; i < Q; i++) {
        int X, V;
        cin >> X >> V;
        insrt_at_any(head, tail, X, V);
    }

    return 0;
}
