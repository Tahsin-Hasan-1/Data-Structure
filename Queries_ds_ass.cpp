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

void insert_at_head(node*& head, node*& tail, int val) {
    node* y = new node(val);
    if (!head) { // 
        head = y;
        tail = y;
    } else {
        y->next = head;
        head = y;
    }
}

void insert_at_tail(node*& head, node*& tail, int val) {
    node* y = new node(val);
    if (!head) {  
        head =y;
         tail = y;
    } else {
        tail->next =y;
        tail = y;
    }
}

void delete_at_index(node*& head, node*& tail, int ind) {
    if (!head) return; 
    if (ind == 0) { // tahsin hasan
        node* t = head;
        head = head->next;
        if (!head) tail = NULL; 
        delete t;
        return;
    }

    node* t1 = head;
    for (int i = 0; i < ind - 1; i++) {
        if (!t1->next) return;
        t1 = t1->next;
    }

    if (!t1->next) return; 
    node* t =t1->next;
    t1->next = t->next;
    if (!t1->next) tail = t1; 
    delete t;
}

void print_at_list(node* head) {
    node* t1 = head;
    while (t1) {
        cout << t1->val << " ";
        t1 = t1->next;
    }
    cout << endl;
}

int main() {
    int Q;  
    cin >> Q;

    node* head = NULL;
    node* tail = NULL;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (X == 0) { 
            insert_at_head(head, tail, V);
        } else if (X == 1) { 
            insert_at_tail(head, tail, V);
        } else if (X == 2) { 
            delete_at_index(head, tail, V);
        }

        
        print_at_list(head);
    }

    return 0;
}
