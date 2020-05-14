#include <iostream>
#include <vector>
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

void MergeKSortedLists(vector <Node*> v1)
{
    if(v1.size() == 0)
    {
        return;
    }
    //cout << v1.size();

    priority_queue <int, vector<int>, greater<int> > pq;
    Node* head = NULL; 

    for(auto itr = v1.begin();itr != v1.end(); itr++)
    {
        Node* tmp = *itr;
        while(tmp!= NULL)
        {
            //cout << tmp->data << " ";
            pq.push(tmp->data);
            tmp = tmp->next;
        }
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

int main()
{
    vector<Node*> v1;
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

    v1.push_back(node1);
    v1.push_back(node2);

    MergeKSortedLists(v1);

}

