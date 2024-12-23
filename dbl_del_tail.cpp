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

void delete_tail(node*& head, node*& tail) {
    node* del = tail;
    tail = tail->prev;
    delete del;
    if (tail == NULL) {
        head == NULL;
        return;
    }
    tail->next = NULL;
}
int main() {
    node* head = new node(10);
    node* a = new node(20);
    node* tail = new node(30);
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;
    delete_tail(head, tail);

    print_forward(head);

    return 0;
}