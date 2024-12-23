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

void insrt_tail(node*& head, int val, node*& tail) {
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
int main() {
    node* head = NULL;
    node* tail = NULL;
    int val;
    while (1) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insrt_tail(head, val, tail);
    }
    print_forward(head);
    return 0;
}