#include <iostream>

using namespace std;

class Node  
{  
    public: 
    bool data;  
    Node* next;  
};  

Node *newNode(bool data)  
{  
    Node *temp = new Node;  
    temp->data = data;  
    temp->next = NULL;  
    return temp;  
} 

int decimalValue(Node *head)
{
    int res =0;
    while (head!= NULL)
    {
        res = (res << 1) + head->data;
        head =head->next;
    }
    return res;
}

int main()
{
    Node* head = newNode(1);  
    head->next = newNode(0);  
    head->next->next = newNode(1);  
    head->next->next->next = newNode(1);

    cout << decimalValue(head);
}
