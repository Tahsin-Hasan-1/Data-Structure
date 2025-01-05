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

void insert_at_head(node*& head, node*& tail, int val) {
    node* n = new node(val);
    if (!head) {
        head = tail = n;
    } else {
        n->next = head;  // tahsin hasan
        head->prev = n;
        head = n;
    }
}

void insert_at_tail(node*& head, node*& tail, int val) {
    node* n = new node(val);
    if (!tail) {
        head = tail = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void delete_at_index(node*& head, node*& tail, int index) {
    if (!head || index < 0) return;
    node* t = head;
    for (int i = 0; i < index && t; ++i) {
        t = t->next;
    }
    if (!t) return;

    if (t->prev)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next)
        t->next->prev = t->prev;
    else
        tail = t->prev;

    delete t;
}

int main() {
    int Q;
    cin >> Q;

    node* head = NULL;
    node* tail = NULL;

    for (int i = 0; i < Q; i++) {
        int X, V;
        cin >> X >> V;
        if (X == 0) {
            insert_at_head(head, tail, V);
        } else if (X == 1) {
            insert_at_tail(head, tail, V);
        } else if (X == 2) {
            delete_at_index(head, tail, V);
        }
        print_forward(head);
        print_reverse(tail);
    }

    return 0;
}
