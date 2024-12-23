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
        tmp = tmp->next;  // tahsin hasan
    }
}
int dif(node*& head) {
    int min = head->val;
    int max = head->val;
    for (node* i = head; i != NULL; i = i->next) {
        if (i->val > min)
            max = i->val;

        else if (i->val < max)
            min = i->val;
    }
    int k = max - min;
    return k;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    int val;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;  // tahsin hasan
        }
        insert_tail(head, tail, val);
    }
    int p = dif(head);
    // print_linked(head);
    cout << p;
    return 0;
}