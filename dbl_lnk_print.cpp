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

void print_backward(node*& tail) {
    node* t = tail;
    while (t) {
        cout << t->val << " ";
        t = t->prev;
    }
    cout << endl;
}
int main() {
    node* head = new node(10);
    node* a = new node(20);
    node* tail = new node(30);
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;
    print_forward(head);
    print_backward(tail);
    return 0;
}