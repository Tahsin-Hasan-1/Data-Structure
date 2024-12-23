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
void print_forward(node*& head) {
    node* t = head;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}

void insrt_at_any(node*& head, int val, int ind) {
    node* t = head;
    node* n = new node(val);
    for (int i = 1; i < ind; i++) {
        t = t->next;
    }
    n->next = t->next;
    t->next->prev = n;
    t->next = n;
    n->prev = t;
}
int main() {
    node* head = new node(10);
    node* a = new node(20);
    node* tail = new node(30);
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;
    insrt_at_any(head, 100, 2);
    print_forward(head);
    return 0;
}