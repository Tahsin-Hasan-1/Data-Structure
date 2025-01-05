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
 void reverse(node* &head, node* tmp)
    {
        if(tmp->next == NULL)
        {
            head = tmp;
            return;
        }
        reverse(head,tmp->next);
        tmp->next->next = tmp;
        tmp->next = NULL;
    }

void insrt_tail(node*& head,  node*& tail,int val) {
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
 bool isPalindrome(node* head) {
        node* newhead = NULL;
        node* newtail = NULL;

        node* tmp = head;
        while(tmp != NULL)
        {
            insrt_tail(newhead, newtail, tmp->val);
            tmp = tmp->next;
        }

        reverse(newhead,newhead);

        tmp = head;
        node* tmp2 = newhead;
        
        while(tmp != NULL)
        {
            if(tmp->val != tmp2->val)
            {
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        return true;
    }  //tahsin hasan

int main() {
      node* head = NULL;
    node* tail = NULL;
    int val;
    while (1) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insrt_tail(head, tail, val);
    }
   
   bool k= isPalindrome(head);
   if(k==true){
    cout<<"YES";
   } else cout<<"NO";
   
    return 0;
}