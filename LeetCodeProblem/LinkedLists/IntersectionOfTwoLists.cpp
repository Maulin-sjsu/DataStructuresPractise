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

int LengthOfLL(Node *node)
{
    int c = 0;
    while(node!= NULL)
    {
        c++;
        node = node->next;
    }
    return c;
}

Node* getFinalIntersectionNode(int d,Node* nodea, Node* nodeb){
    
    Node* curr1 = nodea;
    Node* curr2 = nodeb;
        
        for(int i = 0;i<d;i++)
        {
            if(curr1 == NULL)
            {

                return NULL;
            }
            curr1 = curr1->next;
        }

        while(curr1 != NULL && curr2 != NULL)
        {

            if(curr1->data == curr2->data)
            {

                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;

}

Node* getIntersectionNode(Node* nodeA, Node* nodeB){

    int a = LengthOfLL(nodeA);
    int b = LengthOfLL(nodeB);
    int d =0;

    if(a>b){
        d = a-b;
        return getFinalIntersectionNode(d,nodeA,nodeB);
    }else{
        d = b-a;
        return getFinalIntersectionNode(d,nodeB,nodeA);
    }

}

int main(){

    Node *node1 = new Node(1);
    node1->next = new Node(3);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(7);
    node1->next->next->next->next = new Node(9);

    Node *node2 = new Node(5);
    node2->next = new Node(7);
    node2->next->next = new Node(9);
   // node2->next->next->next = new Node(8);
   // node2->next->next->next->next = new Node(10);

    Node *mau = getIntersectionNode(node1,node2);
    cout <<mau->data <<endl;
}