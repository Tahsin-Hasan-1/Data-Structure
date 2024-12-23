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
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}
void delete_at_pos(node*& head, int ind) {
    node* tmp = head;
    for (int i = 1; i < ind; i++) {
        tmp = tmp->next;
    }
    node* del = tmp->next;
    tmp->next = tmp->next->next;
    delete del;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    int val;
    int ind;
    cin >> ind;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_tail(head, tail, val);
    }
    delete_at_pos(head, ind);
    print_linked(head);
    return 0;
}