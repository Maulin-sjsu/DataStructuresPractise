#include <iostream>
#include <queue>

using namespace std; 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
    Node(int data) 
    { 
        this->data = data; 
        next = NULL; 
    } 
};

void printLinkedList(Node *head)
{
    if(head == NULL){
        return;
    }
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    } 
}


void SortList(Node* head)
{
    priority_queue <int, vector<int>, greater<int> > pq;

    Node* tmp = head;
    while(tmp!= NULL)
    {
        //cout << tmp->data << " ";
        pq.push(tmp->data);
        tmp = tmp->next;
    }

    Node* ln = new Node(-1);
    head = ln;

    while(!pq.empty()){
        head->next = new Node(pq.top());
        pq.pop();
        head = head->next;
    }

    printLinkedList(ln->next);
    
}

int main(){

    Node *node1 = new Node(1);
    node1->next = new Node(13);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(17);
    node1->next->next->next->next = new Node(9);

    SortList(node1);
}