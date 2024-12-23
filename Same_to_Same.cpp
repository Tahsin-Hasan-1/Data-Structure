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

class node1 {
   public:
    int val;
    node1* next;
    node1(int val) {
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

void insert_tail(node1*& head1, node1*& tail1, int val1) {
    node1* newnode = new node1(val1);
    if (head1 == NULL) {
        head1 = newnode;
        tail1 = newnode;
        return;
    }
    tail1->next = newnode;
    tail1 = newnode;
}

void print_linked(node*& head) {
    node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_linked(node1*& head1) {
    node1* tmp = head1;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int same(node*& head, node1* head1) {
    node* t = head;
    node1* t1 = head1;
    while (t != NULL && t1 != NULL) {
        if (t->val != t1->val) {
            return 3;
        }
        t = t->next;  // tahsin
        t1 = t1->next;
    }

    if (t != NULL || t1 != NULL) {
        return 3;
    }

    return 2;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    node1* head1 = NULL;
    node1* tail1 = NULL;
    int val;
    int val1;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_tail(head, tail, val);
    }

    while (true) {
        cin >> val1;
        if (val1 == -1) {
            break;
        }
        insert_tail(head1, tail1, val1);
    }

    int k = same(head, head1);
    if (k == 2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
