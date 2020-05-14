#include <iostream>

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

void MergeTwoList(Node *head1, Node *head2)
{
    if(head1 == NULL && head2 == NULL){
        return;
    }

    Node *tmp = new Node(-1);
    Node *head = tmp;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data)
        {
            tmp->next = head1;
            head1 = head1->next;           
        }else{
            tmp->next = head2;
            head2 = head2->next;
        }
         tmp = tmp->next;
    }
    if(head1 != NULL)
    {
        tmp->next = head1;
    }
    if(head2 != NULL)
    {
        tmp->next = head2;
    }
    printLinkedList(head->next);
} 


int main(){

    Node *node1 = new Node(1);
    node1->next = new Node(3);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(7);
    node1->next->next->next->next = new Node(9);

    Node *node2 = new Node(2);
    node2->next = new Node(4);
    node2->next->next = new Node(6);
    node2->next->next->next = new Node(8);
    node2->next->next->next->next = new Node(10);
    
    MergeTwoList(node1, node2);

    //printLinkedList(node1);

}
