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

int sumOfAllLeaves(Node* node){
    //int sum = 0;
    if(node == NULL)
    {
        return 0;
    } 
    else if(node != NULL && node->left == NULL && node->right == NULL)
    {
        cout << node->data << endl;
        return node->data;
    }
    else {
        cout << "------" <<endl;
        return sumOfAllLeaves(node->left) + sumOfAllLeaves(node->right);
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << sumOfAllLeaves(root);
}