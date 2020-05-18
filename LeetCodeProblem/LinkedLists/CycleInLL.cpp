#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

struct Node { 
    int data; 
    struct Node* next; 
    Node(int data) 
    { 
        this->data = data; 
        next = NULL; 
    } 
};

bool cycleLL(Node* node)
{
    Node* f =  node;
    Node* s =  node;
    
    while(f!= NULL && f->next!= NULL){
        f = f->next->next;
        s = s->next;
        if(s == f)
        {
            return true;
        }
    }
    return false;
}

int main(){

    Node *node1 = new Node(1);
    node1->next = new Node(3);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(7);
    node1->next->next->next->next = node1->next;

    cout << cycleLL(node1);
}

