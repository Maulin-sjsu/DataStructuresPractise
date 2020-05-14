#include <iostream>

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


void SumofTwoLists(Node* node1, Node* node2)
{
    if(node1 == NULL && node2 == NULL)
    {
        return;
    }
    else if(node1 != NULL && node2 == NULL)
    {
        printLinkedList(node2);
    }else if(node2 != NULL && node1 == NULL)
    {
        printLinkedList(node1);
    }

    int carry  =0;
    int sum = 0;
    
    Node *tmp = new Node(-1);
    Node *head = tmp;

    while(node1!= NULL ||  node2!= NULL)
    {
        sum = carry + (node1 ? node1->data : 0) + (node2 ? node2->data:0);
        carry = (sum >= 10)? sum/10 : 0;
        sum = sum%10;
        //cout << sum;
        tmp->next = new Node(sum);
        tmp = tmp->next;

        if(node1) node1 = node1->next;
        if(node2) node2 = node2->next;
    }
    printLinkedList(head->next);
    //return head->next;
}


int main(){
   // vector<Node*> v1;
    Node *node1 = new Node(1);
    node1->next = new Node(3);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(7);
    node1->next->next->next->next = new Node(9);


    Node *node2 = new Node(2);
    node2->next = new Node(4);
    node2->next->next = new Node(6);
    //node2->next->next->next = new Node(8);
    //node2->next->next->next->next = new Node(10);
    SumofTwoLists(node1,node2);
}
