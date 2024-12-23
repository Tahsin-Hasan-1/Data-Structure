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
    if (!head) {      //tahsin hasan
        head = tail = newnode;
    } else {  
        tail->next = newnode;
        tail = newnode;
    }
}


int search(node* head, int X) {
    int ind = 0;
    while (head) {
        if (head->val == X) {
            return ind; 
        }
        head = head->next;
        ind++;
    }
    return -1;  
}

int main() {
    int T;  // tahsin hasan
    cin >> T;

    while (T--) {
        node* head = NULL;
        node* tail = NULL;
        int val;

        
        while (cin >> val && val != -1) {
            insert_tail(head, tail, val);
        }

        int X;
        cin >> X;  

        
        cout << search(head, X) << endl;

        
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
