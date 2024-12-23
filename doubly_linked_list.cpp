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
int main() {
    node* head = new node(10);
    node* a = new node(20);
    node* tail = new node(30);
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;
    return 0;
}