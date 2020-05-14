#include <iostream>
#include <stack>

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
    if(head == NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void printReverseLinkedList(Node *head)
{
    stack <Node*> s1;
    if(head == NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        s1.push(head);
        head = head->next;
    }
    Node *tmp = new Node(-1);
    while(!s1.empty())
    {
        tmp = s1.top();
        cout << tmp->data << " " ;
        s1.pop();
        tmp = tmp->next;
    }
}

void printRLL(Node *head)
{
    if(head == NULL){
        return;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *nxt = NULL;

    while(curr!= NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    printLinkedList(head);
}

int main(){

    Node *node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);
    node->next->next->next->next = new Node(5);

    printLinkedList(node);
    cout << endl;
    printReverseLinkedList(node);
    cout << endl;
    printRLL(node);
    



}
