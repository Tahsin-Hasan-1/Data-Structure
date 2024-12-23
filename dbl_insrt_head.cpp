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

void insrt_head(node*& head,int val) {
  node* t=new node(val);
  t->next=head;
  head->prev=t;
  head=t;
}
int main() {
    node* head = new node(10);
    node* a = new node(20);
    node* b = new node(30);
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    insrt_head(head,100);
    print_forward(head);
    return 0;
}