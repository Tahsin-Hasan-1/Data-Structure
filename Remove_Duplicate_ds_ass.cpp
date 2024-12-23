#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_tail(node*& head, node*& tail, int val) {
    node* newnode = new node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_linked(node*& head) {
    node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void del_dup(node*& head) {
    node* t = head;
    while (t != NULL) {
        node* t1 = t;
        node* del = t->next;
        while (del != NULL) {
            if (del->val == t->val) {
                t1->next = del->next;
                delete del;
                del = t1->next;
            } else {
                t1 = del;
                del = del->next;
            }
        }
        t = t->next;
    }
}  // tahsin

int main() {
    node* head = NULL;
    node* tail = NULL;
    int val;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_tail(head, tail, val);
    }

    del_dup(head);
    print_linked(head);

    return 0;
}
