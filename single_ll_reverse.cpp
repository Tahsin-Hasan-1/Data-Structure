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
void reverse_list(node*& head,node* tmp,node*&tail) {
    if(tmp->next==NULL){
        head=tmp;
        return;
    }
    reverse_list(head,tmp->next,tail);
tmp->next->next=tmp;
tmp->next=NULL;    
tail=tmp;
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
        insert_tail(head, tail, val);
    }
reverse_list(head,head,tail);
    print_linked(head);
    return 0;
}