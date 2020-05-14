#include <iostream>

using namespace std;


struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

bool issymmentrichelper(Node* node1, Node* node2){
    if(node1 == NULL && node2 == NULL)
    {
        return true;
    }
    if(node1->data != node2->data){
        return false;
    }
    return issymmentrichelper(node1->left, node2->right) && issymmentrichelper(node1->right, node2->left);
}

bool issymmentric(Node* node){
    if(node == NULL)
    {
        return true;
    }
    return(issymmentrichelper(node->left, node->right));
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << issymmentric(root);
}