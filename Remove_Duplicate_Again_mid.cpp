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


void sort(node*& head) {
    if (head == NULL || head->next == NULL) {
        return; 
    }

    for (node* i = head; i->next != NULL; i = i->next) {
        for (node* j = i->next; j != NULL; j = j->next) {
            if (i->val > j->val) {
                swap(i->val, j->val);
            }
        }
    }
}


void insert_tail(node*& head, int val, node*& tail) {
    node* t = new node(val);
    if (head == NULL) {
        head = t;
        tail = t;    // tahsin hasan
        return;
    }
    tail->next = t;
    t->prev = tail;
    tail = t;

void del_dup(node*& head) {
    if (head == NULL || head->next == NULL) {
        return; 
    }

    node* t = head;
    while (t != NULL) {
        node* t1 = t;
        node* del = t->next;

        while (del != NULL) {
            if (del->val == t->val) {
                t1->next = del->next;
                if (del->next != NULL) {
                    del->next->prev = t1;
                }
                delete del;
                del = t1->next;
            } else {
                t1 = del;
                del = del->next;
            }
        }
        t = t->next;
    }
}


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


    del_dup(head);
    sort(head);

    print_linked(head);

    return 0;
}
