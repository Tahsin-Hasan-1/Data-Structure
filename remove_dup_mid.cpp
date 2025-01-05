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


void insert_tail(node*& head, int val, node*& tail) {
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

void del_dup(node*& head) {
    if (head == NULL || head->next == NULL) return;

    
    set<int> values;

    
    node* t1 = head;
    while (t1 != NULL) {
        values.insert(curr->val);
        t1 = t1->next;
    }

    
    node* new_head = NULL;
    node* new_tail = NULL;
    for (int val : values) {
        insert_tail(new_head, val, new_tail);
    }

    
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    head = new_head;
}  //tahsin hasan


void print_linked(node* head) {
    node* t = head;
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    int val;

    
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_tail(head, val, tail);
    }


    process_list(head);

    
    print_linked(head);

    return 0;
}
