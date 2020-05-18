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

int SumOfLeafNodes(Node* node){
    if(node == NULL){
        return 0 ;
    }
    //Same can be written for right Subtree
    else if(node->left != NULL && node->left->left == NULL && node->left->right == NULL){
        return node->left->data + SumOfLeafNodes(node->right); 
    }else{
        return SumOfLeafNodes(node->left) + SumOfLeafNodes(node->right);
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

    cout << SumOfLeafNodes(root);
}