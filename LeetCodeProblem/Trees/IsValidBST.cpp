#include<bits/stdc++.h> 

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

    
    bool isValidBST_n(Node* node, int max, int min)
    {
        if(node == NULL)
        {
            return true;
        }
        if(((max != NULL) && (node->data >= max)) || ((min!= NULL) && (node->data <= min)))
        {
            return false;
        }
        else{
            return isValidBST_n(node->left,node->data,min) && isValidBST_n(node->right,max,node->data);
        }
    }

bool isValidBST(Node * root)
    {
        return isValidBST_n(root, NULL , NULL);
    }

int main(){
    Node* root  = new Node(15);
    root->left  = new Node(10);
    root->right  = new Node(20);
    root->left->left  = new Node(8);
    root->left->right  = new Node(12);

    cout << isValidBST(root);
}